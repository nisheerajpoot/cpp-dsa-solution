#include <iostream>
#include <vector>

using namespace std;

class IntervalListIntersections {
public:

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {

        vector<vector<int>> result;

        int i = 0;
        int j = 0;

        while (i < firstList.size() && j < secondList.size()) {

            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            if (start <= end) {
                result.push_back({start, end});
            }

            if (firstList[i][1] < secondList[j][1]) {
                i++;
            }
            else {
                j++;
            }
        }

        return result;
    }
};

int main() {

    vector<vector<int>> firstList = {
        {0, 2},
        {5, 10},
        {13, 23},
        {24, 25}
    };

    vector<vector<int>> secondList = {
        {1, 5},
        {8, 12},
        {15, 24},
        {25, 26}
    };

    IntervalListIntersections obj;

    vector<vector<int>> result = obj.intervalIntersection(firstList, secondList);

    for (vector<int>& interval : result) {

        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}