#include <iostream>
#include <vector>

using namespace std;

class CorporateFlightBookings {
public:

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> diff(n, 0);

        for (auto &b : bookings) {

            int first = b[0] - 1;
            int last = b[1] - 1;
            int seats = b[2];

            diff[first] += seats;

            if (last + 1 < n) {
                diff[last + 1] -= seats;
            }
        }

        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }
};

int main() {

    int n = 5;

    vector<vector<int>> bookings = {
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}
    };

    CorporateFlightBookings obj;

    vector<int> result = obj.corpFlightBookings(bookings, n);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}