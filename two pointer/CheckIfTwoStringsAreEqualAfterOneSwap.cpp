#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CheckIfTwoStringsAreEqualAfterOneSwap {
public:

    bool areAlmostEqual(string s1, string s2) {

        vector<int> diff;

        for (int i = 0; i < s1.size(); i++) {

            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        if (diff.empty()) {
            return true;
        }

        if (diff.size() != 2) {
            return false;
        }

        return s1[diff[0]] == s2[diff[1]] &&
               s1[diff[1]] == s2[diff[0]];
    }
};

int main() {

    string s1 = "bank";
    string s2 = "kanb";

    CheckIfTwoStringsAreEqualAfterOneSwap obj;

    cout << obj.areAlmostEqual(s1, s2);

    return 0;
}