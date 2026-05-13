#include <iostream>
#include <vector>

using namespace std;

class RemoveDuplicatesII {
public:

    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if (n <= 2) {
            return n;
        }

        int index = 2;

        for (int i = 2; i < n; i++) {

            if (nums[i] != nums[index - 2]) {

                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    RemoveDuplicatesII obj;

    int length = obj.removeDuplicates(nums);

    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}