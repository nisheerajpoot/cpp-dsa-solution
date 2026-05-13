#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BoatsToSavePeople {
public:

    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size() - 1;

        int boats = 0;

        while (left <= right) {

            if (people[left] + people[right] <= limit) {
                left++;
            }

            right--;
            boats++;
        }

        return boats;
    }
};

int main() {

    vector<int> people = {3, 2, 2, 1};

    int limit = 3;

    BoatsToSavePeople obj;

    cout << obj.numRescueBoats(people, limit);

    return 0;
}