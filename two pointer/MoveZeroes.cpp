#include <iostream>
#include <vector>

using namespace std;

class MoveZeroes {
public:

    void moveZeroes(vector<int>& nums) {

        int index = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {

                swap(nums[index], nums[i]);
                index++;
            }
        }
    }
};

int main() {

    vector<int> nums = {0, 1, 0, 3, 12};

    MoveZeroes obj;

    obj.moveZeroes(nums);

    for (int value : nums) {
        cout << value << " ";
    }

    return 0;
}