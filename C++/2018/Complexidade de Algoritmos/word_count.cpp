/**
 * @file word_count.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 02/08/2018
 * 
 * Counting words in a .txt file
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>

using std::string;
using std::map;

main(int argc, char const *argv[])
{
	std::ifstream file("lorem_ipsum.txt");

	map<string, unsigned> word_map;
	map<string, unsigned>::iterator iter;

	string word;
	char ch;

	char c;

	while (file.good())
	{
		c = file.get();

		while (c != ' ' && file.good())
		{
			word.push_back(c);
			c = file.get();
		}

		ch = word.back();

		if (ch == '.' || ch == ',' || ch == '?' || ch == '!' || ch == ';')
			word.pop_back();

		iter = word_map.find(word);

		if (iter != word_map.end()) {
			word_map.at(word) += 1;
		} else {
			word_map.insert(std::pair<string, unsigned>(word, 1));
		}
		
		word.erase();
	}

	file.close();

	unsigned i = 0;

	for(auto element : word_map)
	{
		std::cout << std::setw(20) << element.first << std::setw(10) << element.second << std::endl;
		i++;
	}

	std::cout << "\n" << std::setw(20) << "Total words : " << i << std::endl;

	return 0;
}
