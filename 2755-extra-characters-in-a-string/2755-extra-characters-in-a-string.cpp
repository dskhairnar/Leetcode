class Solution {
private:
    unordered_map<string, int> um;  // Dictionary words
    unordered_map<int, int> memo;   // Memoization map for storing results

    int solve(string& s, int ind) {
        // base condition, where recursion gets over
        if (ind >= s.size()) {
            return 0;
        }

        // If the result for this index is already calculated, return it
        if (memo.find(ind) != memo.end()) {
            return memo[ind];
        }

        int extra = INT_MAX;
        string tmp = "";       

        // Try all substrings starting from the current index
        for (int i = ind; i < s.size(); i++) {
            tmp += s[i]; // string concatenation

            if (um.find(tmp) != um.end()) {
                // If the substring is in the dictionary, solve for the remaining part
                extra = min(extra, solve(s, i + 1));
            }
        }

        // Consider the case where the current character is counted as extra
        extra = min(extra, 1 + solve(s, ind + 1));

        // Memoize the result for the current index
        memo[ind] = extra;

        return extra;
    }

public:
    int minExtraChar(string s, vector<string>& dict) {
        for (auto& val : dict) {
            um[val]++;
        }

        // Clear memo map before starting the recursion
        memo.clear();

        return solve(s, 0);  // Start the recursion from index 0
    }
};
