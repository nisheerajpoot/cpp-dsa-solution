#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class LongestDuplicateSubstring {
public:
    string longestDupSubstring(string s) {

        int n = s.size();

        long long base = 31;
        long long mod = 1000000007;

        int left = 1;
        int right = n - 1;

        string answer = "";

        auto check = [&](int len) {

            unordered_set<long long> seen;

            long long hash = 0;
            long long power = 1;

            for (int i = 0; i < len; i++) {
                hash =
                    (hash * base +
                    (s[i] - 'a' + 1)) % mod;

                if (i < len - 1) {
                    power =
                        (power * base) % mod;
                }
            }

            seen.insert(hash);

            for (int i = len; i < n; i++) {

                hash =
                    (
                        (
                            hash -
                            (
                                (s[i - len] - 'a' + 1)
                                * power
                            ) % mod +
                            mod
                        ) % mod
                    );

                hash =
                    (
                        hash * base +
                        (s[i] - 'a' + 1)
                    ) % mod;

                if (seen.count(hash)) {
                    return s.substr(i - len + 1,
                                    len);
                }

                seen.insert(hash);
            }

            return string("");
        };

        while (left <= right) {

            int mid =
                left + (right - left) / 2;

            string current = check(mid);

            if (!current.empty()) {
                answer = current;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};

int main() {
    string s = "banana";

    LongestDuplicateSubstring obj;

    cout << obj.longestDupSubstring(s);

    return 0;
}