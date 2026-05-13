#include <iostream>
#include <vector>

using namespace std;

class IntersectionOfSortedArrays {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        int j = 0;

        vector<int> result;

        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
            else {

                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }

                i++;
                j++;
            }
        }

        return result;
    }
};

int main() {

    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 2, 3, 5};

    IntersectionOfSortedArrays obj;

    vector<int> result = obj.intersection(nums1, nums2);

    for (int value : result) {
        cout << value << " ";
    }

    return 0;
}