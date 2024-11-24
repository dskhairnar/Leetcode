class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
       long long minAbs = LLONG_MAX; // Track the smallest absolute value
        long long sum = 0;           // Sum of absolute values
        int negativeCount = 0;       // Count of negative numbers

        // Traverse the matrix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int value = matrix[i][j];
                sum += abs(value); // Add absolute value to the sum
                minAbs = min(minAbs, (long long)abs(value)); // Track minimum absolute value
                if (value < 0) {
                    negativeCount++; // Count negative numbers
                }
            }
        }

        // If the number of negatives is even, we can make all elements positive
        if (negativeCount % 2 == 0) {
            return sum;
        }

        // If odd, subtract twice the smallest absolute value to maximize the sum
        return sum - 2 * minAbs;
    }
};