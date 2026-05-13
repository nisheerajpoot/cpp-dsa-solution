#include <iostream>
#include <vector>

using namespace std;

class TwoSumII {
public:

    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }

            if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};

int main() {

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    TwoSumII obj;

    vector<int> result = obj.twoSum(numbers, target);

    for (int value : result) {
        cout << value << " ";
    }

    return 0;
}