#pragma once
#include "Pair.h"
#include "Result.h"
#include <vector>

Result MergeSort(std::vector<Pair> data);
void MergeSort(std::vector<Pair>& data, Result& result, int first, int last);

Result Quicksort(std::vector<Pair> data);
void Quicksort(std::vector<Pair>& data, Result& result, int first, int last);

Result BubbleSort(std::vector<Pair> data);

Result HeapSort(std::vector<Pair> data);

Result SelectionSort(std::vector<Pair> data);

Result InsertionSort(std::vector<Pair> data);

void printVector(std::vector<Pair> const& data);