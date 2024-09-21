class Solution {
public:
    vector<int> ans;   // Vector to store the answer
    int n;             // The upper limit up to which numbers are generated

    // Recursive DFS function to generate lexicographical numbers
    void f(int i) {
        if (i > n) return;            // Stop recursion if the current number exceeds n
        if (i > 0) ans.push_back(i);  // Add valid numbers (i > 0) to the result
        
        // Generate the next number by adding digits 0 through 9
        for (int j = (i == 0) ? 1 : 0; j <= 9; j++) {
            int x = 10 * i + j;       // Build the next number
            if (x > n) break;         // Stop if the number exceeds n
            f(x);                     // Recursively explore further numbers
        }
    }

    // Main function to generate the lexicographical order up to n
    vector<int> lexicalOrder(int n) {
        this->n = n;                  // Set the global n
        ans.reserve(n);               // Preallocate space for n elements
        f(0);                         // Start the recursion from 0
        return ans;                   // Return the generated result
    }
};