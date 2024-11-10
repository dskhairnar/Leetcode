class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};

        unordered_map<string, vector<string>> frequencyStringsMap;
        for (const string& str : strs) {
            string frequencyString = getFrequencyString(str);
            frequencyStringsMap[frequencyString].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& pair : frequencyStringsMap) {
            result.push_back(pair.second);
        }
        return result;
    }

private:
    string getFrequencyString(const string& str) {
        vector<int> count(26, 0);
        for (char ch : str) {
            count[ch - 'a']++;
        }
        string frequencyString;
        for (int i = 0; i < 26; ++i) {
            frequencyString += string(count[i], 'a' + i);
        }
        return frequencyString;
    }
};
