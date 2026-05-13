#include <iostream>
#include <vector>

using namespace std;

class PartitionArrayAccordingToGivenPivot {
public:

    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> smaller;
        vector<int> equal;
        vector<int> greater;

        for (int value : nums) {

            if (value < pivot) {
                smaller.push_back(value);
            }
            else if (value == pivot) {
                equal.push_back(value);
            }
            else {
                greater.push_back(value);
            }
        }

        vector<int> result;

        for (int value : smaller) {
            result.push_back(value);
        }

        for (int value : equal) {
            result.push_back(value);
        }

        for (int value : greater) {
            result.push_back(value);
        }

        return result;
    }
};

int main() {

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};

    int pivot = 10;

    PartitionArrayAccordingToGivenPivot obj;

    vector<int> result = obj.pivotArray(nums, pivot);

    for (int value : result) {
        cout << value << " ";
    }

    return 0;
}