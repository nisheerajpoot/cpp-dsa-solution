#include <iostream>
#include <vector>

using namespace std;

class RemoveElement {
public:

    int removeElement(vector<int>& nums, int val) {

        int index = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != val) {

                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};

int main() {

    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    RemoveElement obj;

    int length = obj.removeElement(nums, val);

    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}