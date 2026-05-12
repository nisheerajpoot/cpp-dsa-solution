#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NumberOfMatchingSubsequence {
public:
    bool isSubsequence(string& word,
                       vector<vector<int>>& positions) {

        int currentIndex = -1;

        for (char ch : word) {
            vector<int>& indices =
                positions[ch - 'a'];

            int left = 0;
            int right = indices.size() - 1;

            int nextIndex = -1;

            while (left <= right) {
                int mid =
                    left + (right - left) / 2;

                if (indices[mid] > currentIndex) {
                    nextIndex = indices[mid];
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (nextIndex == -1) {
                return false;
            }

            currentIndex = nextIndex;
        }

        return true;
    }

    int numMatchingSubseq(string s,
                          vector<string>& words) {

        vector<vector<int>> positions(26);

        for (int i = 0; i < s.size(); i++) {
            positions[s[i] - 'a'].push_back(i);
        }

        int count = 0;

        for (string& word : words) {
            if (isSubsequence(word,
                              positions)) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    string s = "abcde";

    vector<string> words = {
        "a",
        "bb",
        "acd",
        "ace"
    };

    NumberOfMatchingSubsequence obj;

    cout << obj.numMatchingSubseq(s,
                                  words);

    return 0;
}