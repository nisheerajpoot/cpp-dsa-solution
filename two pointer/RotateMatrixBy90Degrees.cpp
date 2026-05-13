#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RotateMatrixBy90Degrees {
public:

    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {

            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    RotateMatrixBy90Degrees obj;

    obj.rotate(matrix);

    for (vector<int>& row : matrix) {

        for (int value : row) {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}