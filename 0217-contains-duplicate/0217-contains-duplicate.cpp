class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int n = st.size();
        int m = nums.size();

        if (n == m){
            return false;
        }else{
            return true;
        }
        
        
    }
};