class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowSize = wordLen * wordCount;

        if (s.size() < windowSize) return ans;

        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        // We will iterate over each possible starting point in the word length frame
        for (int i = 0; i < wordLen; ++i) {
            int start = i, matched = 0;
            unordered_map<string, int> curr;

            for (int end = i; end + wordLen <= s.size(); end += wordLen) {
                string endWord = s.substr(end, wordLen);
                if (freq.find(endWord) != freq.end()) {
                    curr[endWord]++;
                    matched++;

                    while (curr[endWord] > freq[endWord]) {
                        string startWord = s.substr(start, wordLen);
                        curr[startWord]--;
                        matched--;
                        start += wordLen;
                    }

                    if (matched == wordCount) {
                        ans.push_back(start);
                    }
                } else {
                    curr.clear();
                    matched = 0;
                    start = end + wordLen;
                }
            }
        }

        return ans;
    }
};
