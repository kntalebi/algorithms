#include <string>
#include <iostream>
#include "Pair.h"
#include "Sort.h"

void IgnoreFirstLine();

void main() {
	IgnoreFirstLine();
	std::string line;

	std::getline(std::cin, line);
	int inputCount = std::stoi(line);
	std::cout << "Num elements: " << inputCount << std::endl;

	std::vector<Pair> data(inputCount);

	for(int i = 0; i < inputCount; ++i)
	{
		std::cin >> line;

		auto start = line.find_first_of('(');
		auto comma = line.find_first_of(',');
		auto end = line.find_first_of(')');

		int first = std::stoi(line.substr(start + 1, comma - start - 1));
		int second = std::stoi(line.substr(comma + 1, end - comma - 1));

		data[i] = Pair(first, second);		
	}

	Result qsResult = Quicksort(data);

    Result bsResult = BubbleSort(data);

    Result msResult = MergeSort(data);

	Result hsResult = HeapSort(data);

	Result ssResult = SelectionSort(data);

	Result isResult = InsertionSort(data);
}

void IgnoreFirstLine()
{
	std::string garbage;
	std::getline(std::cin, garbage);
}

