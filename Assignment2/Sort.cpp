#include "Sort.h"
#include <iostream>

void Merge(std::vector<Pair>& data, int first, int middle, int last);

void MergeSort(std::vector<Pair> data)
{
	MergeSort(data, 0, data.size() - 1);
}


void MergeSort(std::vector<Pair>& data, int first, int last)
{
	int middle = (first + last) / 2;

	if (first < last) {
		MergeSort(data, first, middle);
		MergeSort(data, middle + 1, last);
		Merge(data, first, middle, last);
	}
}

void Merge(std::vector<Pair>& data, int first, int middle, int last)
{
	std::vector<Pair> merged(last - first + 1);
	int i = first, j = middle + 1, k = 0;
	while (i <= middle && j <= last)
	{
		if (data[i] <= data[j])
		{
			merged[k] = data[i];
			++k;
			++i;
		}
		else {
			merged[k] = data[j];
			++k;
			++j;
		}
	}

	while (i <= middle) {
		merged[k] = data[i];
		++k;
		++i;
	}

	while (j <= last) {
		merged[k] = data[j];
		++k;
		++j;
	}
	for (i = first; i < last; ++i) {
		data[i] = merged[i - first];
	}
}


int Partition(std::vector<Pair>& data, int first, int last);

void Quicksort(std::vector<Pair> data)
{
	Quicksort(data, 0, data.size() - 1);
}

void Quicksort(std::vector<Pair>& data, int first, int last)
{
	if (first < last) {
		int middle = Partition(data, first, last);
		Quicksort(data, first, middle - 1);
		Quicksort(data, middle + 1, last);
	}
}

int Partition(std::vector<Pair>& data, int first, int last)
{
	Pair pivot = data[first];	
	int h = first;

	for (int k = first + 1; k <= last; ++k)
	{
		if (data[k] < pivot)
		{
			h++;
			std::swap(data[h], data[k]);
		}
	}
	std::swap(data[first], data[h]);
	return h;
}

void BubbleSort(std::vector<Pair> data)
{
	int n = data.size() - 1;
	int i;
	bool flag = true;
	int iteration = 0;
	while (flag)
	{
		flag = false;
		for (i = 1; i < n - iteration; ++i)
		{
			if (data[i] < data[i - 1])
			{
				std::swap(data[i], data[i - 1]);
				flag = true;
			}
		}
		iteration++;
	}
}

void Heapify(std::vector<Pair>& data, int i, int heapSize);
void BuildHeap(std::vector<Pair>& data, int heapSize);
int Left(int i);
int Right(int i);

void HeapSort(std::vector<Pair> data)
{
	int heapSize = data.size();
	BuildHeap(data, heapSize);
	for (int i = heapSize - 1; i >= 1; --i)
	{
		std::swap(data[0], data[i]);
		heapSize--;
		Heapify(data, 0, heapSize);
	}
}

void BuildHeap(std::vector<Pair>& data, int heapSize)
{
	for(int i = heapSize/2; i >= 0; --i)
	{
		Heapify(data, i, heapSize);
	}
}

void Heapify(std::vector<Pair>& data, int i, int heapSize)
{
	int smallest;
	int l = Left(i);
	int r = Right(i);

	if(l < heapSize && data[l] < data[i])
		smallest = l;
	else
		smallest = i;

	if(r < heapSize && data[r] < data[smallest])
		smallest = r;

	if(smallest != i)
	{
		std::swap(data[i], data[smallest]);
		Heapify(data, smallest, heapSize);
	}
}

int Left(int i)
{
	return 2 * i + 1;
}

int Right(int i)
{
	return 2 * i + 2;
}

void SelectionSort(std::vector<Pair> data)
{
	int n = data.size();
	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (data[j] < data[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			std::swap(data[i], data[min]);
			;
		}

	}
}

void InsertionSort(std::vector<Pair> data)
{
	int n = data.size();
	for (int i = 1; i < n; ++i)
	{
		Pair current = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > current)
		{
			data[j + 1] = data[j];
			j--;
;		}
		data[j + 1] = current;
	}
}

void printVector(std::vector<Pair> const& data) {
	for (const Pair& val : data)
	{
		std::cout << "(" << val.first << "," << val.second << ")";
	}
}