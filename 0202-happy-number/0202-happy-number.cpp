class Solution {
public:
    bool isHappy(int n) {
      std::unordered_set<int> usedIntegers; // Corrected type and instantiation
        while (true) {
            int sum = 0;
            while (n != 0) {
                sum += std::pow(n % 10, 2); // 'std::pow' for exponentiation
                n /= 10;
            }

            if (sum == 1) return true;

            if (usedIntegers.count(sum)) // Checks for a cycle
                return false;

            usedIntegers.insert(sum);
            n = sum; // Update n to the sum of squares
        }
    }
};