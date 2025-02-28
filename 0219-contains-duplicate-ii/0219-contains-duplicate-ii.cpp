class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // Stores the last index of each number
        
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
                return true; // Found a duplicate within range k
            }
            mp[nums[i]] = i; // Update the index of the current element
        }
        
        return false; // No such pair found
    }
};
