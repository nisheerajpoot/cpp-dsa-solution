#include <iostream>
#include <string>

using namespace std;

class MinimumMovesToMakePalindrome {
public:

    int minMovesToMakePalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        int moves = 0;

        while (left < right) {

            int current = right;

            while (current > left && s[current] != s[left]) {
                current--;
            }

            if (current == left) {

                swap(s[left], s[left + 1]);

                moves++;
            }
            else {

                while (current < right) {

                    swap(s[current], s[current + 1]);

                    moves++;

                    current++;
                }

                left++;
                right--;
            }
        }

        return moves;
    }
};

int main() {

    string s = "aabb";

    MinimumMovesToMakePalindrome obj;

    cout << obj.minMovesToMakePalindrome(s);

    return 0;
}