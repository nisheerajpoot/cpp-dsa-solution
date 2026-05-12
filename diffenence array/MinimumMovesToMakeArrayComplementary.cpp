#include <iostream>
#include <vector>

using namespace std;

class MinimumMovesToMakeArrayComplementary {
public:

    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - i - 1];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int sum = a + b;

            diff[2] += 2;

            diff[low] -= 1;

            diff[sum] -= 1;

            diff[sum + 1] += 1;

            diff[high + 1] += 1;
        }

        int answer = n;

        int moves = 0;

        for (int s = 2; s <= 2 * limit; s++) {

            moves += diff[s];

            answer = min(answer, moves);
        }

        return answer;
    }
};

int main() {

    vector<int> nums = {1, 2, 4, 3};

    int limit = 4;

    MinimumMovesToMakeArrayComplementary obj;

    cout << obj.minMoves(nums, limit);

    return 0;
}