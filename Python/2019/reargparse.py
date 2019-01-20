# https://docs.python.org/3/library/re.html
import re
# https://docs.python.org/3/library/argparse.html
import argparse

def Main():

	parser = argparse.ArgumentParser()
	parser.add_argument('word', help='Specify word to search for')
	parser.add_argument('fname', help='Specify file to search')

	args = parser.parse_args()

	search_file = open(args.fname)

	line_num = 0

	for line in search_file.readlines():
		line = line.strip('\n\r')
		line_num += 1
		search_result = re.search(args.word, line, re.M | re.I)

		if search_result:
			print("{:5}: {}".format(line_num, line))

	search_file.close()


if __name__ == '__main__':
	Main()