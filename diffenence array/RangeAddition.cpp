#include <iostream>
#include <vector>

using namespace std;

class RangeAddition {
public:

    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {

        vector<int> diff(length, 0);

        for (auto &u : updates) {

            int start = u[0];
            int end = u[1];
            int val = u[2];

            diff[start] += val;

            if (end + 1 < length) {
                diff[end + 1] -= val;
            }
        }

        for (int i = 1; i < length; i++) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }
};

int main() {

    int length = 5;

    vector<vector<int>> updates = {
        {1, 3, 2},
        {2, 4, 3},
        {0, 2, -2}
    };

    RangeAddition obj;

    vector<int> result = obj.getModifiedArray(length, updates);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}