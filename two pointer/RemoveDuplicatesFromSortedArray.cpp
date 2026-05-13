#include <iostream>
#include <vector>

using namespace std;

class RemoveDuplicatesFromSortedArray {
public:

    int removeDuplicates(vector<int>& nums) {

        int index = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] != nums[i - 1]) {

                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};

int main() {

    vector<int> nums = {1, 1, 2};

    RemoveDuplicatesFromSortedArray obj;

    int length = obj.removeDuplicates(nums);

    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}