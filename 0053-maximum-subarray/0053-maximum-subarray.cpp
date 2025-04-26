class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0]; // initialize with first element

        for (int i = 0; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
