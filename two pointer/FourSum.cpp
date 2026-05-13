#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FourSum {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {

                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }

                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {

    vector<int> nums = {1, 0, -1, 0, -2, 2};

    int target = 0;

    FourSum obj;

    vector<vector<int>> result = obj.fourSum(nums, target);

    for (vector<int>& quad : result) {

        for (int value : quad) {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}