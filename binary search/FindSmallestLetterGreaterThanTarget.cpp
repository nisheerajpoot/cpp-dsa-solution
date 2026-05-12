#include <iostream>
#include <vector>

using namespace std;

class FindSmallestLetterGreaterThanTarget {
public:
    char nextGreatestLetter(vector<char>& letters,
                            char target) {

        int left = 0;
        int right = letters.size() - 1;

        char answer = letters[0];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target) {
                answer = letters[mid];
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};

int main() {
    vector<char> letters = {'c', 'f', 'j'};

    char target = 'a';

    FindSmallestLetterGreaterThanTarget obj;

    cout << obj.nextGreatestLetter(letters,
                                   target);

    return 0;
}