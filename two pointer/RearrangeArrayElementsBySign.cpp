#include <iostream>
#include <vector>

using namespace std;

class RearrangeArrayElementsBySign {
public:

    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> result(n);

        int positiveIndex = 0;
        int negativeIndex = 1;

        for (int value : nums) {

            if (value > 0) {

                result[positiveIndex] = value;
                positiveIndex += 2;
            }
            else {

                result[negativeIndex] = value;
                negativeIndex += 2;
            }
        }

        return result;
    }
};

int main() {

    vector<int> nums = {3, 1, -2, -5, 2, -4};

    RearrangeArrayElementsBySign obj;

    vector<int> result = obj.rearrangeArray(nums);

    for (int value : result) {
        cout << value << " ";
    }

    return 0;
}