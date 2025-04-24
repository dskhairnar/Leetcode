class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n  = nums.size();
        unordered_set<int> st(begin(nums), end(nums));
        int c = st.size();
        unordered_map<int,int> map;
        int i = 0;
        int j = 0;
        int res = 0;

        while(j < n){
            map[nums[j]]++;

            while(map.size() == c){
                res += (n-j);

                map[nums[i]]--;
                if(map[nums[i]] == 0){
                    map.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};