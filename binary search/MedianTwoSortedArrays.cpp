#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MedianTwoSortedArrays {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int left = 0;
        int right = n1;

        while (left <= right) {
            int cut1 = left + (right - left) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }

                return max(l1, l2);
            }

            if (l1 > r2) {
                right = cut1 - 1;
            } else {
                left = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    MedianTwoSortedArrays obj;

    cout << obj.findMedianSortedArrays(nums1, nums2);

    return 0;
}