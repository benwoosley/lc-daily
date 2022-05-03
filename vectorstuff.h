#pragma once
#include <vector>
#include <iostream>

std::vector<int> create_vector(int arr[], int size)
{
    std::vector<int> vec;
    for (int i = 0; i < size; i++)
    {
        vec.push_back(arr[i]);
    }
    return vec;
}

void print_vector(std::vector<int> values)
{
    for (int i = 0; i < values.size(); i++)
    {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}
