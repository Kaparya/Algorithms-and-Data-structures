#include "generate_table.h"
#include "linear_search.h"
#include "binary_search.h"
#include "exponential_search.h"
#include "constants.h"
#include "clock.h"

#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    Clock clock;
    int starts = 100;

    std::vector<std::vector<std::vector<int>>> data;
    for (int i = 1; i <= HEIGHT; i *= 2) {
        auto table = HyperbolicTableGeneration(i);
        data.push_back(table);
    }

    std::vector<double> time(14, 0);
    for (int j = 0; j < starts; j++) {
        int ind = 0;
        for (int index = 0; index <= 13; ++index) {
            int target = 2 * HEIGHT + 1;

            clock.start();
            ExponentialSearch(data[index], target);
            clock.finish();

            std::cout << index << " " << std::fixed << std::setprecision(6) << clock.result() << " milliseconds | ";
            time[ind++] += clock.result();
        }
        std::cout << std::endl;
    }

    for (size_t index = 0; index < 14; ++index) {
        std::cout << time[index] / starts << "\n";
    }

    return 0;
}
