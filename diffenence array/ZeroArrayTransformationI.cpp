#include <iostream>
#include <vector>

using namespace std;

class ZeroArrayTransformationI {
public:

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        vector<int> diff(n + 1, 0);

        for (auto &q : queries) {

            int left = q[0];
            int right = q[1];

            diff[left]++;

            if (right + 1 < n) {
                diff[right + 1]--;
            }
        }

        int operations = 0;

        for (int i = 0; i < n; i++) {

            operations += diff[i];

            if (operations < nums[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    vector<int> nums = {1, 0, 1};

    vector<vector<int>> queries = {
        {0, 2}
    };

    ZeroArrayTransformationI obj;

    cout << (obj.isZeroArray(nums, queries) ? "true" : "false");

    return 0;
}