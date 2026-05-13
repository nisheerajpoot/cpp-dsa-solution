#include <iostream>
#include <string>

using namespace std;

class AppendCharactersToStringToMakeSubsequence {
public:

    int appendCharacters(string s, string t) {

        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size()) {

            if (s[i] == t[j]) {
                j++;
            }

            i++;
        }

        return t.size() - j;
    }
};

int main() {

    string s = "coaching";
    string t = "coding";

    AppendCharactersToStringToMakeSubsequence obj;

    cout << obj.appendCharacters(s, t);

    return 0;
}