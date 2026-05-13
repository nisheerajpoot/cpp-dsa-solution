#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TwoSumTarget {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int remaining = target - nums[i];

            if (mp.count(remaining)) {
                return {mp[remaining], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    TwoSumTarget obj;

    vector<int> result = obj.twoSum(nums, target);

    for (int value : result) {
        cout << value << " ";
    }

    return 0;
}