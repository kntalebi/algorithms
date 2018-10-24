#pragma once
#include "Pair.h"
#include <vector>

void MergeSort(std::vector<Pair> data);
void MergeSort(std::vector<Pair>& data, int first, int last);

void Quicksort(std::vector<Pair> data);
void Quicksort(std::vector<Pair>& data, int first, int last);

void BubbleSort(std::vector<Pair> data);

void HeapSort(std::vector<Pair> data);

void SelectionSort(std::vector<Pair> data);

void InsertionSort(std::vector<Pair> data);

void printVector(std::vector<Pair> const& data);