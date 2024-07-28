class Solution {
public:
    bool canJump(vector<int>& nums) {
         int finalPosition = nums.size() - 1;  // Target index to reach
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= finalPosition) {
                finalPosition = i;  // Move the target to the current index
            }
        }
        return finalPosition == 0;
    }
};