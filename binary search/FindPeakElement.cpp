#include <iostream>
#include <vector>

using namespace std;

class FindPeakElement {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};

    FindPeakElement obj;

    cout << obj.findPeakElement(nums);

    return 0;
}