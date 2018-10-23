#include <string>
#include <iostream>
#include <vector>
#include "Pair.h"

void IgnoreFirstLine();

void main() {
	IgnoreFirstLine();
	std::string line;

	std::getline(std::cin, line);
	int inputCount = std::stoi(line);
	std::cout << "Num elements: " << inputCount << std::endl;

	std::vector<std::pair<int, int>> data;
	data.resize(inputCount);

	for(int i = 0; i < inputCount; ++i)
	{
		std::cin >> line;

		auto start = line.find_first_of('(');
		auto comma = line.find_first_of(',');
		auto end = line.find_first_of(')');

		int first = stoi(line.substr(start + 1, comma - start - 1));
		int second = stoi(line.substr(comma + 1, end - comma - 1));

		data.emplace_back(Pair(first, second));
		
		// std::cout << "(" << first << "," << second << ")" << std::endl;
	}
}

void IgnoreFirstLine()
{
	std::string garbage;
	std::getline(std::cin, garbage);
}
