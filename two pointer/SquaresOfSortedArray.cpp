#include <iostream>
#include <vector>

using namespace std;

class SquaresOfSortedArray {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> result(n);

        int left = 0;
        int right = n - 1;

        int index = n - 1;

        while (left <= right) {

            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {

                result[index] = leftSquare;
                left++;
            }
            else {

                result[index] = rightSquare;
                right--;
            }

            index--;
        }

        return result;
    }
};

int main() {

    vector<int> nums = {-7, -3, 2, 3, 11};

    SquaresOfSortedArray obj;

    vector<int> result = obj.sortedSquares(nums);

    for (int value : result) {
        cout << value << " ";
    }

    return 0;
}