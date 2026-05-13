#include <iostream>
#include <string>

using namespace std;

class SplitTwoStringsToMakePalindrome {
public:

    bool isPalindrome(string& s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool check(string& a, string& b) {

        int left = 0;
        int right = a.size() - 1;

        while (left < right && a[left] == b[right]) {

            left++;
            right--;
        }

        return isPalindrome(a, left, right) ||
               isPalindrome(b, left, right);
    }

    bool checkPalindromeFormation(string a, string b) {

        return check(a, b) || check(b, a);
    }
};

int main() {

    string a = "x";
    string b = "y";

    SplitTwoStringsToMakePalindrome obj;

    cout << obj.checkPalindromeFormation(a, b);

    return 0;
}