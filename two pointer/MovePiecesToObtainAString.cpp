#include <iostream>
#include <string>

using namespace std;

class MovePiecesToObtainAString {
public:

    bool canChange(string start, string target) {

        int i = 0;
        int j = 0;

        int n = start.size();

        while (i < n || j < n) {

            while (i < n && start[i] == '_') {
                i++;
            }

            while (j < n && target[j] == '_') {
                j++;
            }

            if (i == n || j == n) {
                return i == n && j == n;
            }

            if (start[i] != target[j]) {
                return false;
            }

            if (start[i] == 'L' && i < j) {
                return false;
            }

            if (start[i] == 'R' && i > j) {
                return false;
            }

            i++;
            j++;
        }

        return true;
    }
};

int main() {

    string start = "_L__R__R_";
    string target = "L______RR";

    MovePiecesToObtainAString obj;

    cout << obj.canChange(start, target);

    return 0;
}