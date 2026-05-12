#include <iostream>
#include <vector>

using namespace std;

class SingleElementSortedArray {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mid % 2 == 1) {
                mid--;
            }

            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    SingleElementSortedArray obj;

    cout << obj.singleNonDuplicate(nums);

    return 0;
}