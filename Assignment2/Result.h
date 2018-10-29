#pragma once
#include "Pair.h"
#include <vector>
#include <ctime>
#include <iostream>
#include <fstream>

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

    double getTime() const
    {
        return (float)(endTime - startTime) / CLOCKS_PER_SEC;
    }

    bool incrementSteps(long long val = 1)
    {
        mSteps += val;
        return true;
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

    void printResult() const
    {
        std::cout << "Time spent: " << this->getTime() << " seconds" << std::endl;
        std::cout << "Step count: " << this->getSteps() << std::endl;
        std::cout << "Sorted data set:" << std::endl;
        // for(auto& pair : mData)
        // {
        //     std::cout << "(" << pair.first << "," << pair.second << ")";
        // }
        // std::cout << std::endl;
    }

    void printToFile(std::ofstream& out) const
    {
        out << "Time spent: " << this->getTime() << " seconds" << std::endl;
        out << "Step count: " << this->getSteps() << std::endl;
        out << std::endl;
    }

private:
    std::vector<Pair> mData;
    long long mSteps;
    clock_t startTime;
    clock_t endTime;
};
