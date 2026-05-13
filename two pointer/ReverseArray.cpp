#include <iostream>
#include <vector>

using namespace std;

class ReverseArray {
public:
    void reverseArray(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            swap(nums[left], nums[right]);

            left++;
            right--;
        }
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4, 5};

    ReverseArray obj;

    obj.reverseArray(nums);

    for (int value : nums) {
        cout << value << " ";
    }

    return 0;
}