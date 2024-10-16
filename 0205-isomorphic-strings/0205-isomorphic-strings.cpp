class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Two hash maps: one for s -> t mapping, another for t -> s mapping
        unordered_map<char, char> m, y;

        // Check if the sizes of the two strings are the same
        if (s.size() != t.size()) return false;

        // Loop through the characters in both strings
        for (int i = 0; i < s.size(); i++) {
            // If the character s[i] is not yet mapped and t[i] is not yet mapped
            if (m.find(s[i]) == m.end() && y.find(t[i]) == y.end()) {
                // Create a new mapping: s[i] -> t[i] and t[i] -> s[i]
                m[s[i]] = t[i];
                y[t[i]] = s[i];
            } 
            // If the mapping already exists but doesn't match, return false
            else if (m[s[i]] != t[i] || y[t[i]] != s[i]) {
                return false;
            }
        }
        return true;  // All mappings are consistent, return true
    }
};
