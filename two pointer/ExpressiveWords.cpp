#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ExpressiveWords {
public:

    bool isStretchy(string s, string word) {

        int i = 0;
        int j = 0;

        while (i < s.size() && j < word.size()) {

            if (s[i] != word[j]) {
                return false;
            }

            char current = s[i];

            int countS = 0;

            while (i < s.size() && s[i] == current) {
                countS++;
                i++;
            }

            int countWord = 0;

            while (j < word.size() && word[j] == current) {
                countWord++;
                j++;
            }

            if (countS < countWord) {
                return false;
            }

            if (countS != countWord && countS < 3) {
                return false;
            }
        }

        return i == s.size() && j == word.size();
    }

    int expressiveWords(string s, vector<string>& words) {

        int count = 0;

        for (string& word : words) {

            if (isStretchy(s, word)) {
                count++;
            }
        }

        return count;
    }
};

int main() {

    string s = "heeellooo";

    vector<string> words = {
        "hello",
        "hi",
        "helo"
    };

    ExpressiveWords obj;

    cout << obj.expressiveWords(s, words);

    return 0;
}