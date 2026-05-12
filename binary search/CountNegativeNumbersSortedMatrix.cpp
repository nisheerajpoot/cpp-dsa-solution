#include <iostream>
#include <vector>

using namespace std;

class CountNegativeNumbersSortedMatrix {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for (auto& row : grid) {
            int left = 0;
            int right = row.size() - 1;

            int index = row.size();

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (row[mid] < 0) {
                    index = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            count += row.size() - index;
        }

        return count;
    }
};

int main() {
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    CountNegativeNumbersSortedMatrix obj;

    cout << obj.countNegatives(grid);

    return 0;
}