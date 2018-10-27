#pragma once
#include "Pair.h"
#include <vector>
#include <ctime>
class Result
{
public:
    Result() {}

    void startTimer()
    {
        startTime = clock();
        endTime = 0;
    }

    void endTimer()
    {
        endTime = clock();
    }

    clock_t getTime() const
    {
        return endTime - startTime;
    }

    void incrementSteps(long long val = 1)
    {
        mSteps += val;
    }

    long long getSteps() const
    {
        return mSteps;
    }

    std::vector<Pair>& getData()
    {
        return mData;
    }

    void setData(std::vector<Pair> data)
    {
        mData = data;
    }

private:
    std::vector<Pair> mData;
    long long mSteps;
    clock_t startTime;
    clock_t endTime;
};