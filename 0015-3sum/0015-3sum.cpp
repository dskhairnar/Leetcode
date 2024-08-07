class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
        
        if(nums.size() < 3) return result;

        sort(nums.begin(), nums.end());
        set<vector<int>> resultSet;

        for(size_t i = 0; i < nums.size() - 2; ++i) {
            size_t left = i + 1;
            size_t right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {
                    resultSet.insert({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                } else if(sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        for(const auto& triplet : resultSet) {
            result.push_back(triplet);
        }

        return result;
    }
};