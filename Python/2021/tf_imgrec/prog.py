import cv2
import numpy as np
import tensorflow as tf

physdev = tf.config.list_physical_devices('GPU')

if len(physdev) > 0:
    print(physdev)
    tf.config.experimental.set_memory_growth(physdev[0], True)
else:
    print('¯\_(ツ)_/¯')

if __name__ == '__main__':
    model = tf.keras.models.load_model('./model')
    print(model.summary())
    print(f'Input shape  : {model.input_shape}')
    print(f'Output shape : {model.output_shape}')

    cap = cv2.VideoCapture(0)

    while True:
        _, frame = cap.read()
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        gray = cv2.resize(gray, (300, 300))

        cv2.imshow("Input to CNN", gray)

        cnn_input = gray.reshape(300, 300, 1)
        cnn_input = cnn_input / 255.0
        cnn_input = cnn_input.astype('float32')
        cnn_input = np.expand_dims(cnn_input, axis=0)

        # 0 - Rock, 1 - Paper, 2 -> Scissors
        result = model(cnn_input)[0].numpy()

        category = np.argmax(result)

        text = '????'
        min_threshold = 0.5

        if category == 0 and result[category] > min_threshold:
            text = 'Rock'
        elif category == 1 and result[category] > min_threshold:
            text = 'Paper'
        elif category == 2 and result[category] > min_threshold:
            text = 'Scissors'

        # (480, 640, 3)
        cv2.putText(frame, text, (10, frame.shape[0] - 10),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 0), 2)
        cv2.putText(frame, f'[{result[0]:.2f}, {result[1]:.2f}, {result[2]:.2f}]', (10, 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 1)

        cv2.imshow("Original", frame)

        if cv2.waitKey(1) == ord("q"):
            break

    cap.release()
    cv2.destroyAllWindows()
