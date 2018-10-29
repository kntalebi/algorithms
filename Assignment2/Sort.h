#pragma once
#include "Pair.h"
#include "Result.h"
#include <vector>

/*
 * Counting operations:
 * - array index -> 1
 * - assignment -> 1
 * - addition/subtraction/mult/div -> 1
 * - i++ -> 1
 * - std::swap -> 3
 * - return when not returning meta data (I.e. Result) -> 1
 */

Result MergeSort(std::vector<Pair> data);
void MergeSort(std::vector<Pair>& data, Result& result, int first, int last);

Result Quicksort(std::vector<Pair> data);
void Quicksort(std::vector<Pair>& data, Result& result, int first, int last);

Result BubbleSort(std::vector<Pair> data);

Result HeapSort(std::vector<Pair> data);

Result SelectionSort(std::vector<Pair> data);

Result InsertionSort(std::vector<Pair> data);

void printVector(std::vector<Pair> const& data);