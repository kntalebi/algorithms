#include "Sort.h"
#include <iostream>
#include "Result.h"

void Merge(std::vector<Pair>& data, Result& result, int first, int middle, int last);

Result MergeSort(std::vector<Pair> data)
{
    Result result;
    result.startTimer();
    MergeSort(data, result, 0, data.size() - 1);
    result.endTimer();
    result.setData(data);
    return result;
}

void MergeSort(std::vector<Pair>& data, Result& result, int first, int last)
{
	int middle = (first + last) / 2;

	if (first < last) {
		MergeSort(data, result, first, middle);
		MergeSort(data, result, middle + 1, last);
		Merge(data, result, first, middle, last);
	}
}

void Merge(std::vector<Pair>& data, Result& result, int first, int middle, int last)
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


int Partition(std::vector<Pair>& data, Result& result, int first, int last);

Result Quicksort(std::vector<Pair> data)
{
    Result result;
    result.startTimer();
    Quicksort(data, result, 0, data.size() - 1);
    result.endTimer();
    result.setData(data);
    return result;
}

void Quicksort(std::vector<Pair>& data, Result& result, int first, int last)
{
	if (first < last) {
		int middle = Partition(data, result, first, last);
		Quicksort(data, result, first, middle - 1);
		Quicksort(data, result, middle + 1, last);
	}
}

int Partition(std::vector<Pair>& data, Result& result, int first, int last)
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

Result BubbleSort(std::vector<Pair> data)
{
    Result result;
    result.startTimer();

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

    result.endTimer();
    result.setData(data);
    return result;
}

void Heapify(std::vector<Pair>& data, Result& result, int i, int heapSize);
void BuildHeap(std::vector<Pair>& data, Result& result, int heapSize);

Result HeapSort(std::vector<Pair> data)
{
    Result result;
    result.startTimer();
    int heapSize = data.size();
	BuildHeap(data, result, heapSize);
	for (int i = heapSize - 1; i >= 1; --i)
	{
		std::swap(data[0], data[i]);
		heapSize--;
		Heapify(data, result, 0, heapSize);
	}

    result.endTimer();
    result.setData(data);
    return result;
}

void BuildHeap(std::vector<Pair>& data, Result& result, int heapSize)
{
	for(int i = heapSize/2; i >= 0; --i)
	{
		Heapify(data, result, i, heapSize);
	}
}

void Heapify(std::vector<Pair>& data, Result& result, int i, int heapSize)
{
	int smallest;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < heapSize && data[l] < data[i])
		smallest = l;
	else
		smallest = i;

	if(r < heapSize && data[r] < data[smallest])
		smallest = r;

	if(smallest != i)
	{
		std::swap(data[i], data[smallest]);
		Heapify(data, result, smallest, heapSize);
	}
}

Result SelectionSort(std::vector<Pair> data)
{
    Result result;
    result.startTimer();

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

    result.endTimer();
    result.setData(data);
    return result;
}

Result InsertionSort(std::vector<Pair> data)
{
    Result result;
    result.startTimer();
    
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
 
    result.endTimer();
    result.setData(data);
    return result;
}

void printVector(std::vector<Pair> const& data) {
	for (const Pair& val : data)
	{
		std::cout << "(" << val.first << "," << val.second << ")";
	}
}