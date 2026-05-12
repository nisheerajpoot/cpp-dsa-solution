#include <iostream>
#include <vector>

using namespace std;

class PointsThatIntersectWithCars {
public:

    int numberOfPoints(vector<vector<int>>& nums) {

        vector<int> diff(102, 0);

        for (auto &car : nums) {

            int start = car[0];
            int end = car[1];

            diff[start]++;

            if (end + 1 < 102) {
                diff[end + 1]--;
            }
        }

        int points = 0;
        int active = 0;

        for (int i = 1; i < 102; i++) {

            active += diff[i];

            if (active > 0) {
                points++;
            }
        }

        return points;
    }
};

int main() {

    vector<vector<int>> nums = {
        {3, 6},
        {1, 5},
        {4, 7}
    };

    PointsThatIntersectWithCars obj;

    cout << obj.numberOfPoints(nums);

    return 0;
}