#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class SentenceSimilarityIII {
public:

    vector<string> getWords(string sentence) {

        vector<string> words;

        stringstream ss(sentence);

        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {

        vector<string> words1 = getWords(sentence1);
        vector<string> words2 = getWords(sentence2);

        int left = 0;

        while (left < words1.size() &&
               left < words2.size() &&
               words1[left] == words2[left]) {

            left++;
        }

        int right1 = words1.size() - 1;
        int right2 = words2.size() - 1;

        while (right1 >= left &&
               right2 >= left &&
               words1[right1] == words2[right2]) {

            right1--;
            right2--;
        }

        return right1 < left || right2 < left;
    }
};

int main() {

    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";

    SentenceSimilarityIII obj;

    cout << obj.areSentencesSimilar(sentence1, sentence2);

    return 0;
}