#include <iostream>
#include <vector>

using namespace std;

class MaximumPopulationYear {
public:

    int maximumPopulation(vector<vector<int>>& logs) {

        vector<int> diff(101, 0);

        for (auto &log : logs) {

            int birth = log[0] - 1950;
            int death = log[1] - 1950;

            diff[birth]++;

            if (death < 101) {
                diff[death]--;
            }
        }

        int maxPopulation = 0;
        int year = 1950;
        int currentPopulation = 0;

        for (int i = 0; i < 101; i++) {

            currentPopulation += diff[i];

            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                year = 1950 + i;
            }
        }

        return year;
    }
};

int main() {

    vector<vector<int>> logs = {
        {1993, 1999},
        {2000, 2010}
    };

    MaximumPopulationYear obj;

    cout << obj.maximumPopulation(logs);

    return 0;
}