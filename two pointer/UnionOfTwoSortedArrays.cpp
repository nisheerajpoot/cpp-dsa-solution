#include <iostream>
#include <vector>

using namespace std;

class UnionOfTwoSortedArrays {
public:

    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        int j = 0;

        vector<int> result;

        while (i < nums1.size() && j < nums2.size()) {

            int value;

            if (nums1[i] < nums2[j]) {
                value = nums1[i++];
            }
            else if (nums1[i] > nums2[j]) {
                value = nums2[j++];
            }
            else {
                value = nums1[i];
                i++;
                j++;
            }

            if (result.empty() || result.back() != value) {
                result.push_back(value);
            }
        }

        while (i < nums1.size()) {

            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }

            i++;
        }

        while (j < nums2.size()) {

            if (result.empty() || result.back() != nums2[j]) {
                result.push_back(nums2[j]);
            }

            j++;
        }

        return result;
    }
};

int main() {

    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 3, 5};

    UnionOfTwoSortedArrays obj;

    vector<int> result = obj.unionArray(nums1, nums2);

    for (int value : result) {
        cout << value << " ";
    }

    return 0;
}