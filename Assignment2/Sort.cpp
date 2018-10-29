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
        result.incrementSteps();
	}
    result.incrementSteps(4); // includes steps to calculate middle
}

void Merge(std::vector<Pair>& data, Result& result, int first, int middle, int last)
{
	std::vector<Pair> merged(last - first + 1); // Construction/assignment of vector -> 1
	int i = first,
    j = middle + 1, 
    k = 0;

    result.incrementSteps(7);

	while (result.incrementSteps() && i <= middle && result.incrementSteps() && j <= last)
	{
		if (data[i] <= data[j])
		{
			merged[k] = data[i];
			++k;
			++i;
            result.incrementSteps(5);
		}
		else {
			merged[k] = data[j];
			++k;
			++j;
            result.incrementSteps(5);
		}
        result.incrementSteps(3);
	}

	while (result.incrementSteps() && i <= middle) {
		merged[k] = data[i];
		++k;
		++i;
        result.incrementSteps(5);
	}

	while (result.incrementSteps() && j <= last) {
		merged[k] = data[j];
		++k;
		++j;
        result.incrementSteps(5);
	}
    result.incrementSteps(); // i initialization
	for (i = first; result.incrementSteps() && i <= last; ++i, result.incrementSteps()) {
		data[i] = merged[i - first];
        result.incrementSteps(4);
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
        result.incrementSteps(3);
	}
}

int Partition(std::vector<Pair>& data, Result& result, int first, int last)
{
	Pair pivot = data[first];	
	int h = first;

    result.incrementSteps(5); // Includes k initialization

	for (int k = first + 1; result.incrementSteps() && k <= last; ++k, result.incrementSteps())
	{
		if (data[k] < pivot)
		{
			h++;
			std::swap(data[h], data[k]);
            result.incrementSteps(6);
		}
        result.incrementSteps(2);
	}
	std::swap(data[first], data[h]);
    result.incrementSteps(6); // Includes return
    return h;
}

Result BubbleSort(std::vector<Pair> data)
{
    Result result;
    result.startTimer();

    int n = data.size();
	bool flag = true;
	int iteration = 0;

    result.incrementSteps(4); // includes last while check

	while (flag)
	{
		flag = false;
        result.incrementSteps(2); // includes i initialization

		for (int i = 1; result.incrementSteps(2) && i < n - iteration; ++i, result.incrementSteps())
		{
			if (data[i] < data[i - 1])
			{
				std::swap(data[i], data[i - 1]);
				flag = true;
                result.incrementSteps(7);
			}
            result.incrementSteps(4);
		}
		iteration++;
        result.incrementSteps();
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
    result.incrementSteps(3); // Includes i initialization
    for (int i = heapSize - 1; result.incrementSteps() && i >= 1; --i, result.incrementSteps())
	{
		std::swap(data[0], data[i]);
		heapSize--;
		Heapify(data, result, 0, heapSize);
        result.incrementSteps(6);
	}

    result.endTimer();
    result.setData(data);
    return result;
}

void BuildHeap(std::vector<Pair>& data, Result& result, int heapSize)
{
    result.incrementSteps(2); // i initialization
	for(int i = heapSize/2; result.incrementSteps() && i >= 0; --i, result.incrementSteps())
	{
		Heapify(data, result, i, heapSize);
	}
}

void Heapify(std::vector<Pair>& data, Result& result, int i, int heapSize)
{
	int smallest;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

    result.incrementSteps(7); // smallest is getting initialized to 0, so add an extra step

    if (result.incrementSteps() && l < heapSize &&
        result.incrementSteps(3) && data[l] < data[i])
    {
        smallest = l;
        result.incrementSteps();
    }
	else
	{
        smallest = i;
        result.incrementSteps();
	}

	if (result.incrementSteps() && r < heapSize &&
        result.incrementSteps(3) && data[r] < data[smallest])
	{
        smallest = r;
        result.incrementSteps();
	}

	if(smallest != i)
	{
		std::swap(data[i], data[smallest]);
		Heapify(data, result, smallest, heapSize);
        result.incrementSteps(5);
	}
    result.incrementSteps();
}

Result SelectionSort(std::vector<Pair> data)
{
    Result result;
    result.startTimer();

	int n = data.size();
    result.incrementSteps(2); // Include i initialization

	for (int i = 0; result.incrementSteps(2) && i < n - 1; ++i, result.incrementSteps())
	{
		int min = i;
        result.incrementSteps(3); // Include j initialization

		for (int j = i + 1; result.incrementSteps() && j < n; ++j, result.incrementSteps())
		{
			if (data[j] < data[min])
			{
				min = j;
                result.incrementSteps();
			}
            result.incrementSteps(3);
		}
		if (min != i)
		{
			std::swap(data[i], data[min]);
            result.incrementSteps(5);
		}
        result.incrementSteps();
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
    result.incrementSteps(2); // Include i initialization
	for (int i = 1; result.incrementSteps() && i < n; ++i, result.incrementSteps())
    {
		Pair current = data[i];
		int j = i - 1;
        result.incrementSteps(4);

		while (result.incrementSteps() && j >= 0 && result.incrementSteps(2) && data[j] > current)
		{
			data[j + 1] = data[j];
			j--;
            result.incrementSteps(5);
;		}
		data[j + 1] = current;
        result.incrementSteps(3);
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