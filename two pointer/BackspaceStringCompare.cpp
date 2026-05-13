#include <iostream>
#include <string>

using namespace std;

class BackspaceStringCompare {
public:

    bool backspaceCompare(string s, string t) {

        int i = s.size() - 1;
        int j = t.size() - 1;

        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0) {

            while (i >= 0) {

                if (s[i] == '#') {
                    skipS++;
                    i--;
                }
                else if (skipS > 0) {
                    skipS--;
                    i--;
                }
                else {
                    break;
                }
            }

            while (j >= 0) {

                if (t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if (skipT > 0) {
                    skipT--;
                    j--;
                }
                else {
                    break;
                }
            }

            char first = i >= 0 ? s[i] : '#';
            char second = j >= 0 ? t[j] : '#';

            if (first != second) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};

int main() {

    string s = "ab#c";
    string t = "ad#c";

    BackspaceStringCompare obj;

    cout << obj.backspaceCompare(s, t);

    return 0;
}