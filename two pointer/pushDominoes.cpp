#include <iostream>
#include <string>

using namespace std;

class PushDominoes {
public:

    string pushDominoes(string dominoes) {

        int n = dominoes.size();

        int left = -1;

        char leftForce = 'L';

        for (int right = 0; right <= n; right++) {

            char rightForce = right == n ? 'R' : dominoes[right];

            if (rightForce == '.') {
                continue;
            }

            if (leftForce == rightForce) {

                for (int k = left + 1; k < right; k++) {
                    dominoes[k] = rightForce;
                }
            }
            else if (leftForce == 'R' && rightForce == 'L') {

                int low = left + 1;
                int high = right - 1;

                while (low < high) {

                    dominoes[low++] = 'R';
                    dominoes[high--] = 'L';
                }
            }

            left = right;
            leftForce = rightForce;
        }

        return dominoes;
    }
};

int main() {

    string dominoes = ".L.R...LR..L..";

    PushDominoes obj;

    cout << obj.pushDominoes(dominoes);

    return 0;
}