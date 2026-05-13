#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class ThreeSumClosest {
public:

    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int currentSum = nums[i] + nums[left] + nums[right];

                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                }
                else if (currentSum > target) {
                    right--;
                }
                else {
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};

int main() {

    vector<int> nums = {-1, 2, 1, -4};

    int target = 1;

    ThreeSumClosest obj;

    cout << obj.threeSumClosest(nums, target);

    return 0;
}