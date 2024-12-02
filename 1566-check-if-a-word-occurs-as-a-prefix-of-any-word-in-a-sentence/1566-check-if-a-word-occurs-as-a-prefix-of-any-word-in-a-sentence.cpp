class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);  // To split the sentence into words
        string word;
        int wordIndex = 0;

        while (stream >> word) {  // Read each word from the sentence
            wordIndex++;
            if (word.find(searchWord) == 0) {  // Check if searchWord is a prefix
                return wordIndex;  // Return the 1-based index of the word
            }
        }

        return -1;  // If no word starts with searchWord
    }
};