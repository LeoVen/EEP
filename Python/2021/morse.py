# Leonardo Vencovsky
# 2021/03/10
# https://github.com/LeoVen

# Letters are separated by a single space
# Words are separated by three spaces

encript = {
    'A': '.-',
    'B': '-...',
    'C': '-.-.',
    'D': '-..',
    'E': '.',
    'F': '..-.',
    'G': '--.',
    'H': '....',
    'I': '..',
    'J': '.---',
    'K': '-.-',
    'L': '.-..',
    'M': '--',
    'N': '-.',
    'O': '---',
    'P': '.--.',
    'Q': '--.-',
    'R': '.-.',
    'S': '...',
    'T': '-',
    'U': '..-',
    'V': '...-',
    'W': '.--',
    'X': '-..-',
    'Y': '-.--',
    'Z': '--..',
    '1': '.----',
    '2': '..---',
    '3': '...--',
    '4': '....-',
    '5': '.....',
    '6': '-....',
    '7': '--...',
    '8': '---..',
    '9': '----.',
    '0': '-----',
    ' ': ' '
}

decript = {v: k for k, v in encript.items()}

def encript_message(message):
    encripted = ''
    for letter in message.strip().upper():
        tokens = encript.get(letter)
        if tokens is None:
            encripted += '[?]'
        else:
            encripted += encript[letter] + ' '
    return encripted

def decript_message(message):
    decripted = ''
    for word in message.strip().upper().split('   '):
        for tokens in word.split(' '):
            letter = decript.get(tokens)
            if letter is None:
                decripted += '[?]'
            else:
                decripted += letter
        decripted += ' '
    return decripted

msg = 'hello world'

print(encript_message(msg))
print(decript_message(encript_message(msg)))
