#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BagOfTokens {
public:

    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(), tokens.end());

        int left = 0;
        int right = tokens.size() - 1;

        int score = 0;
        int maximumScore = 0;

        while (left <= right) {

            if (power >= tokens[left]) {

                power -= tokens[left];
                score++;

                maximumScore = max(maximumScore, score);

                left++;
            }
            else if (score > 0) {

                power += tokens[right];
                score--;

                right--;
            }
            else {
                break;
            }
        }

        return maximumScore;
    }
};

int main() {

    vector<int> tokens = {100, 200, 300, 400};

    int power = 200;

    BagOfTokens obj;

    cout << obj.bagOfTokensScore(tokens, power);

    return 0;
}