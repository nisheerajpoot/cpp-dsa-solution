#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ShiftingLettersII {
public:

    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.length();

        vector<int> diff(n + 1, 0);

        for (auto &shift : shifts) {

            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 1) {
                diff[start] += 1;

                if (end + 1 < n) {
                    diff[end + 1] -= 1;
                }
            }
            else {

                diff[start] -= 1;

                if (end + 1 < n) {
                    diff[end + 1] += 1;
                }
            }
        }

        int currentShift = 0;

        for (int i = 0; i < n; i++) {

            currentShift += diff[i];

            int offset = (s[i] - 'a' + currentShift) % 26;

            if (offset < 0) {
                offset += 26;
            }

            s[i] = offset + 'a';
        }

        return s;
    }
};

int main() {

    string s = "abc";

    vector<vector<int>> shifts = {
        {0, 1, 0},
        {1, 2, 1},
        {0, 2, 1}
    };

    ShiftingLettersII obj;

    cout << obj.shiftingLetters(s, shifts);

    return 0;
}