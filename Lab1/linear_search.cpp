#pragma once

#include <vector>

bool LinearSearch(const std::vector<std::vector<int>>& data, const int& value) {

    size_t height = data.size(), width = data[0].size();
    size_t row = 0, column = width - 1;

    while (row < height && column >= 0) {
        if (data[row][column] == value) {
            return true;
        }

        if (data[row][column] < value) {
            ++row;
        } else {
            --column;
        }
    }

    return false;
}