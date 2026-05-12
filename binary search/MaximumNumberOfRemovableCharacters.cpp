#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MaximumNumberOfRemovableCharacters {
public:
    bool isSubsequence(string& s,
                       string& p,
                       vector<int>& removable,
                       int k) {

        vector<bool> removed(s.size(), false);

        for (int i = 0; i < k; i++) {
            removed[removable[i]] = true;
        }

        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (!removed[i] &&
                j < p.size() &&
                s[i] == p[j]) {
                j++;
            }
        }

        return j == p.size();
    }

    int maximumRemovals(string s,
                        string p,
                        vector<int>& removable) {

        int left = 0;
        int right = removable.size();

        int answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isSubsequence(s,
                              p,
                              removable,
                              mid)) {

                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};

int main() {
    string s = "abcacb";
    string p = "ab";

    vector<int> removable = {3,1,0};

    MaximumNumberOfRemovableCharacters obj;

    cout << obj.maximumRemovals(s,
                                p,
                                removable);

    return 0;
}