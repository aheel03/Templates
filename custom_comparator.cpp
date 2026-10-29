#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::pair<int, int>> vec = {{1, 5}, {3, 2}, {1, 3}, {2, 8}};

    // Sort using an inline lambda function
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        // Return true if 'a' should come before 'b'
        if (a.first != b.first) {
            return a.first < b.first; // Primary sort: Ascending by .first
        }
        return a.second > b.second;   // Secondary sort: Descending by .second
    });
}
