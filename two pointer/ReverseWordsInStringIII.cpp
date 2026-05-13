#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReverseWordsInStringIII {
public:

    string reverseWords(string s) {

        int start = 0;

        for (int end = 0; end <= s.size(); end++) {

            if (end == s.size() || s[end] == ' ') {

                reverse(s.begin() + start, s.begin() + end);

                start = end + 1;
            }
        }

        return s;
    }
};

int main() {

    string s = "Let's take LeetCode contest";

    ReverseWordsInStringIII obj;

    cout << obj.reverseWords(s);

    return 0;
}