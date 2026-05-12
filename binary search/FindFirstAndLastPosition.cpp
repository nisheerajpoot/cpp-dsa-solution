#include <iostream>
#include <vector>

using namespace std;

class FindFirstAndLastPosition {
public:
    int firstPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target) {
                    answer = mid;
                }

                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    int lastPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target) {
                    answer = mid;
                }

                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstPosition(nums, target), lastPosition(nums, target)};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    FindFirstAndLastPosition obj;

    vector<int> result = obj.searchRange(nums, target);

    cout << result[0] << " " << result[1];

    return 0;
}