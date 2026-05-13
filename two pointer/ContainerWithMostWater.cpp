#include <iostream>
#include <vector>

using namespace std;

class ContainerWithMostWater {
public:

    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int maximumArea = 0;

        while (left < right) {

            int width = right - left;

            int currentHeight = min(height[left], height[right]);

            maximumArea = max(maximumArea, width * currentHeight);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maximumArea;
    }
};

int main() {

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    ContainerWithMostWater obj;

    cout << obj.maxArea(height);

    return 0;
}