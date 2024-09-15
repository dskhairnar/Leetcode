class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Map to store the first occurrence of each bitmask
        map<int, int> mp;
        mp[0] = -1;  // Initialize for the case where the whole substring has even counts
        int cnt = 0, ans = 0;
        
        // Iterate over the string
        for (int i = 0; i < s.size(); i++) {
            // Toggle bits based on the vowels
            if (s[i] == 'a') cnt ^= (1 << 0); // Toggle the bit for 'a'
            if (s[i] == 'e') cnt ^= (1 << 1); // Toggle the bit for 'e'
            if (s[i] == 'i') cnt ^= (1 << 2); // Toggle the bit for 'i'
            if (s[i] == 'o') cnt ^= (1 << 3); // Toggle the bit for 'o'
            if (s[i] == 'u') cnt ^= (1 << 4); // Toggle the bit for 'u'
            
            // If this bitmask has been seen before, calculate the length of the substring
            if (mp.count(cnt)) {
                ans = max(ans, i - mp[cnt]);  // Update the maximum length
            } else {
                mp[cnt] = i;  // Store the first occurrence of this bitmask
            }
        }
        
        return ans;
    }
};
