#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class ValidPalindrome {
public:

    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {

    string s = "A man, a plan, a canal: Panama";

    ValidPalindrome obj;

    cout << obj.isPalindrome(s);

    return 0;
}