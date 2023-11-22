#include <vector>

std::vector<std::vector<int>> OrdinaryTableGeneration(const int& width) {
    int height = 8192;

    std::vector<std::vector<int>> result(height, std::vector<int>(width));

    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            result[row][column] = (height / width * row + column) * 2;
        }
    }

    return result;
}

std::vector<std::vector<int>> HyperbolicTableGeneration(const int& width) {
    int height = 8192;

    std::vector<std::vector<int>> result(height, std::vector<int>(width));

    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            result[row][column] = (height / width * row * column) * 2;
        }
    }

    return result;
}
