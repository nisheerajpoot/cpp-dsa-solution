#include <iostream>
#include <string>

using namespace std;

class LongestPalindromicSubstring {
public:

    int expand(string& s, int left, int right) {

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            left--;
            right++;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {

            int oddLength = expand(s, i, i);
            int evenLength = expand(s, i, i + 1);

            int currentLength = max(oddLength, evenLength);

            if (currentLength > maxLength) {

                maxLength = currentLength;

                start = i - (currentLength - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};

int main() {

    string s = "babad";

    LongestPalindromicSubstring obj;

    cout << obj.longestPalindrome(s);

    return 0;
}