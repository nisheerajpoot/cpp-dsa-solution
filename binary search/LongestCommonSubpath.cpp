#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class LongestCommonSubpath {
public:
    bool check(int len,
               vector<vector<int>>& paths) {

        long long base = 100001;
        long long mod = 1000000007;

        unordered_set<long long> common;

        bool firstPath = true;

        for (auto& path : paths) {

            unordered_set<long long> current;

            long long hash = 0;
            long long power = 1;

            for (int i = 0; i < len; i++) {

                hash =
                    (hash * base + path[i]) % mod;

                if (i < len - 1) {
                    power =
                        (power * base) % mod;
                }
            }

            current.insert(hash);

            for (int i = len;
                 i < path.size();
                 i++) {

                hash =
                    (
                        (
                            hash -
                            (
                                path[i - len]
                                * power
                            ) % mod +
                            mod
                        ) % mod
                    );

                hash =
                    (hash * base +
                    path[i]) % mod;

                current.insert(hash);
            }

            if (firstPath) {
                common = current;
                firstPath = false;
            } else {

                unordered_set<long long> next;

                for (auto value : current) {
                    if (common.count(value)) {
                        next.insert(value);
                    }
                }

                common = next;
            }

            if (common.empty()) {
                return false;
            }
        }

        return true;
    }

    int longestCommonSubpath(int n,
                             vector<vector<int>>& paths) {

        int minLength = paths[0].size();

        for (auto& path : paths) {
            minLength =
                min(minLength,
                    (int)path.size());
        }

        int left = 0;
        int right = minLength;

        int answer = 0;

        while (left <= right) {

            int mid =
                left + (right - left) / 2;

            if (check(mid, paths)) {
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
    int n = 5;

    vector<vector<int>> paths = {
        {0,1,2,3,4},
        {2,3,4},
        {4,0,1,2,3}
    };

    LongestCommonSubpath obj;

    cout << obj.longestCommonSubpath(n,
                                     paths);

    return 0;
}