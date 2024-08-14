class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Sort the array to simplify distance calculation
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.back() - nums.front();  // Max possible distance

        // Binary search on distance
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0, j = 0;

            // Count pairs with a distance <= mid using two-pointer technique
            for (int i = 0; i < nums.size(); ++i) {
                while (j < nums.size() && nums[j] - nums[i] <= mid) {
                    ++j;
                }
                count += j - i - 1;
            }

            // Adjust the binary search range based on the count
            if (count < k) {
                left = mid + 1;  // Increase the distance
            } else {
                right = mid;  // Decrease the distance
            }
        }

        return left;  // The k-th smallest distance
    }
};
