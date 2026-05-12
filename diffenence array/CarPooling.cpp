#include <iostream>
#include <vector>

using namespace std;

class CarPooling {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> diff(1001, 0);

        for (auto &t : trips) {

            int passengers = t[0];
            int from = t[1];
            int to = t[2];

            diff[from] += passengers;
            diff[to] -= passengers;
        }

        int currentPassengers = 0;

        for (int i = 0; i < 1001; i++) {

            currentPassengers += diff[i];

            if (currentPassengers > capacity) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    vector<vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7}
    };

    int capacity = 4;

    CarPooling obj;

    cout << (obj.carPooling(trips, capacity) ? "true" : "false");

    return 0;
}