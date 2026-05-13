#include <iostream>
#include <vector>

using namespace std;

class WaterPlantsII {
public:

    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {

        int left = 0;
        int right = plants.size() - 1;

        int currentA = capacityA;
        int currentB = capacityB;

        int refill = 0;

        while (left < right) {

            if (currentA < plants[left]) {

                refill++;
                currentA = capacityA;
            }

            currentA -= plants[left];
            left++;

            if (currentB < plants[right]) {

                refill++;
                currentB = capacityB;
            }

            currentB -= plants[right];
            right--;
        }

        if (left == right) {

            if (max(currentA, currentB) < plants[left]) {
                refill++;
            }
        }

        return refill;
    }
};

int main() {

    vector<int> plants = {2, 2, 3, 3};

    int capacityA = 5;
    int capacityB = 5;

    WaterPlantsII obj;

    cout << obj.minimumRefill(plants, capacityA, capacityB);

    return 0;
}