#include <iostream>
#include <vector>

using namespace std;

class FindPeakElementII {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int left = 0;
        int right = cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int maxRow = 0;

            for (int i = 0; i < rows; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int leftValue = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1;
            int rightValue = mid + 1 < cols ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > leftValue &&
                mat[maxRow][mid] > rightValue) {
                return {maxRow, mid};
            }

            if (mat[maxRow][mid] < rightValue) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {-1, -1};
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 4},
        {3, 2}
    };

    FindPeakElementII obj;

    vector<int> result = obj.findPeakGrid(mat);

    cout << result[0] << " " << result[1];

    return 0;
}