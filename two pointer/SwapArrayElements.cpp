#include <iostream>
#include <vector>

using namespace std;

class SwapArrayElements {
public:
    void swapElements(vector<int>& nums, int firstIndex, int secondIndex) {
        swap(nums[firstIndex], nums[secondIndex]);
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4, 5};

    int firstIndex = 1;
    int secondIndex = 3;

    SwapArrayElements obj;

    obj.swapElements(nums, firstIndex, secondIndex);

    for (int value : nums) {
        cout << value << " ";
    }

    return 0;
}