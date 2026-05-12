#include <iostream>
#include <vector>

using namespace std;

class ApplyOperationsToMakeAllArrayElementsEqualToZero {
public:

    bool checkArray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> diff(n + 1, 0);

        int current = 0;

        for (int i = 0; i < n; i++) {

            current += diff[i];

            nums[i] += current;

            if (nums[i] < 0) {
                return false;
            }

            if (nums[i] == 0) {
                continue;
            }

            if (i + k > n) {
                return false;
            }

            int val = nums[i];

            current -= val;

            if (i + k < n) {
                diff[i + k] += val;
            }
        }

        return true;
    }
};

int main() {

    vector<int> nums = {2, 2, 3, 1, 1, 0};

    int k = 3;

    ApplyOperationsToMakeAllArrayElementsEqualToZero obj;

    cout << (obj.checkArray(nums, k) ? "true" : "false");

    return 0;
}