#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CamelcaseMatching {
public:

    bool check(string query, string pattern) {

        int j = 0;

        for (char ch : query) {

            if (j < pattern.size() && ch == pattern[j]) {
                j++;
            }
            else if (isupper(ch)) {
                return false;
            }
        }

        return j == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {

        vector<bool> result;

        for (string& query : queries) {
            result.push_back(check(query, pattern));
        }

        return result;
    }
};

int main() {

    vector<string> queries = {
        "FooBar",
        "FooBarTest",
        "FootBall",
        "FrameBuffer",
        "ForceFeedBack"
    };

    string pattern = "FB";

    CamelcaseMatching obj;

    vector<bool> result = obj.camelMatch(queries, pattern);

    for (bool value : result) {
        cout << value << " ";
    }

    return 0;
}