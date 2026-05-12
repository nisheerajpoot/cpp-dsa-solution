#include <iostream>
#include <vector>

using namespace std;

class MountainArray {
public:
    vector<int> arr;

    MountainArray(vector<int> nums) {
        arr = nums;
    }

    int get(int index) {
        return arr[index];
    }

    int length() {
        return arr.size();
    }
};

class FindInMountainArray {
public:
    int peakIndex(MountainArray& mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) <
                mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    int binarySearch(MountainArray& mountainArr,
                     int left,
                     int right,
                     int target,
                     bool ascending) {

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            }

            if (ascending) {
                if (value < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (value > target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }

    int findInMountainArray(int target,
                            MountainArray& mountainArr) {

        int peak = peakIndex(mountainArr);

        int leftSearch =
            binarySearch(mountainArr,
                         0,
                         peak,
                         target,
                         true);

        if (leftSearch != -1) {
            return leftSearch;
        }

        return binarySearch(mountainArr,
                            peak + 1,
                            mountainArr.length() - 1,
                            target,
                            false);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 3, 1};

    int target = 3;

    MountainArray mountainArr(nums);

    FindInMountainArray obj;

    cout << obj.findInMountainArray(target,
                                    mountainArr);

    return 0;
}