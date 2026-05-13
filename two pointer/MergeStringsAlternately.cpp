#include <iostream>
#include <string>

using namespace std;

class MergeStringsAlternately {
public:

    string mergeAlternately(string word1, string word2) {

        string result;

        int i = 0;
        int j = 0;

        while (i < word1.size() || j < word2.size()) {

            if (i < word1.size()) {
                result += word1[i++];
            }

            if (j < word2.size()) {
                result += word2[j++];
            }
        }

        return result;
    }
};

int main() {

    string word1 = "abc";
    string word2 = "pqr";

    MergeStringsAlternately obj;

    cout << obj.mergeAlternately(word1, word2);

    return 0;
}