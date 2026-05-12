#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MinimumTimeToRevertWordInitialStateII {
public:
    int minimumTimeToInitialState(string word,
                                  int k) {

        int n = word.size();

        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {

            if (word[i] == word[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {

                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int longestPrefixSuffix =
            lps[n - 1];

        while (longestPrefixSuffix > 0) {

            int removed =
                n - longestPrefixSuffix;

            if (removed % k == 0) {
                return removed / k;
            }

            longestPrefixSuffix =
                lps[longestPrefixSuffix - 1];
        }

        return (n + k - 1) / k;
    }
};

int main() {
    string word = "abacaba";

    int k = 3;

    MinimumTimeToRevertWordInitialStateII obj;

    cout << obj.minimumTimeToInitialState(word,
                                          k);

    return 0;
}
