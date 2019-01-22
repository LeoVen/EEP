# #
# analysis.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 07/05/2018
#
# Data is calculated in Ohms
# #
import pandas as pd

def main():

	data_frame = pd.read_csv('data/experiment_data.csv')

	df_len = len(data_frame)

	df_values = data_frame.values

	theory = []
	real = []

	for i in range(df_len):
		theory.append(df_values[i][0])
		real.append(df_values[i][1])

	diff = []

	for i in range(df_len):
		diff.append(( theory[i] - real[i] ) / real[i] )

		if (diff[i] < 0):
			diff[i] *= -1

	s = 0

	for i in range(df_len):
		s += diff[i]

	error_rate = s / df_len

	print(error_rate)


if __name__ == '__main__':
	main()