#include <string>
#include <iostream>
#include "Pair.h"
#include "Sort.h"
#include <fstream>

void IgnoreFirstLine();

void main() {
	// IgnoreFirstLine();
	std::string line;
    std::getline(std::cin, line);
    int optionNumber = std::stoi(line);

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
        // std::cout << "(" << first << "," << second << ")";
	}

    // std::cout << "Quick Sort started" << std::endl;
    // Result qsResult = Quicksort(data);
    // std::cout << "Quick Sort ended" << std::endl;
    // qsResult.printResult();

    // std::cout << "Bubble Sort started" << std::endl;
    // Result bsResult = BubbleSort(data);
    // std::cout << "Bubble Sort ended" << std::endl;
    // bsResult.printResult();

    std::cout << "Merge Sort started" << std::endl;
    Result msResult = MergeSort(data);
    std::cout << "Merge Sort ended" << std::endl;
    msResult.printResult();

    std::cout << "Heap Sort started" << std::endl;
	Result hsResult = HeapSort(data);
    std::cout << "Heap Sort ended" << std::endl;
    hsResult.printResult();

 //    std::cout << "Selection Sort started" << std::endl;
	// Result ssResult = SelectionSort(data);
 //    std::cout << "Selection Sort ended" << std::endl;
 //    ssResult.printResult();

    std::cout << "Insertion Sort started" << std::endl;
	Result isResult = InsertionSort(data);
    std::cout << "Insertion Sort ended" << std::endl;
    isResult.printResult();

    std::string fileName = "option-" + std::to_string(optionNumber) + "/out-" + std::to_string(inputCount) + ".txt";
    std::ofstream out (fileName);
    if (out.is_open())
    {
        // out << "Quick Sort" << std::endl;
        // qsResult.printToFile(out);

        // out << "Bubble Sort" << std::endl;
        // bsResult.printToFile(out);

        out << "Merge Sort" << std::endl;
        msResult.printToFile(out);

        out << "Heap Sort" << std::endl;
        hsResult.printToFile(out);

        // out << "Selection Sort" << std::endl;
        // ssResult.printToFile(out);

        out << "Insertion Sort" << std::endl;
        isResult.printToFile(out);

        out.close();
    }
}

void IgnoreFirstLine()
{
	std::string garbage;
	std::getline(std::cin, garbage);
}

