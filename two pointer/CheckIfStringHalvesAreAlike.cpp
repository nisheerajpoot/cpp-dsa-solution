#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class CheckIfStringHalvesAreAlike {
public:

    bool halvesAreAlike(string s) {

        unordered_set<char> vowels = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        };

        int leftCount = 0;
        int rightCount = 0;

        int n = s.size();

        for (int i = 0; i < n / 2; i++) {

            if (vowels.count(s[i])) {
                leftCount++;
            }
        }

        for (int i = n / 2; i < n; i++) {

            if (vowels.count(s[i])) {
                rightCount++;
            }
        }

        return leftCount == rightCount;
    }
};

int main() {

    string s = "book";

    CheckIfStringHalvesAreAlike obj;

    cout << obj.halvesAreAlike(s);

    return 0;
}