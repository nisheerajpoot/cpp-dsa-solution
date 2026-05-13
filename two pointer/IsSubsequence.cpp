#include <iostream>
#include <string>

using namespace std;

class IsSubsequence {
public:

    bool isSubsequence(string s, string t) {

        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size()) {

            if (s[i] == t[j]) {
                i++;
            }

            j++;
        }

        return i == s.size();
    }
};

int main() {

    string s = "abc";
    string t = "ahbgdc";

    IsSubsequence obj;

    cout << obj.isSubsequence(s, t);

    return 0;
}