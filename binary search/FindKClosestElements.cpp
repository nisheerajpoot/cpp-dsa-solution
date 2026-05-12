#include <iostream>
#include <vector>

using namespace std;

class FindKClosestElements {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return vector<int>(arr.begin() + left,
                           arr.begin() + left + k);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    int k = 4;
    int x = 3;

    FindKClosestElements obj;

    vector<int> result = obj.findClosestElements(arr, k, x);

    for (int value : result) {
        cout << value << " ";
    }

    return 0;
}