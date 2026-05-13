#include <iostream>
#include <vector>

using namespace std;

class SortZeroAndOne {
public:

    void sortArray(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            if (nums[left] == 0) {
                left++;
            }
            else if (nums[right] == 1) {
                right--;
            }
            else {

                swap(nums[left], nums[right]);

                left++;
                right--;
            }
        }
    }
};

int main() {

    vector<int> nums = {1, 0, 1, 0, 1, 0};

    SortZeroAndOne obj;

    obj.sortArray(nums);

    for (int value : nums) {
        cout << value << " ";
    }

    return 0;
}