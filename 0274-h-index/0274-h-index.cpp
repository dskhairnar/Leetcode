class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        if (citations.empty()) return 0;

        std::sort(citations.begin(), citations.end());

        int result = 0;
        int n = citations.size();

        for (int i = 0; i < n; ++i) {
            // Determine the current H-index
            int curH = std::min(citations[i], n - i);
            // Update the result with the maximum H-index found
            result = std::max(result, curH);
        }

        return result;
    }
};
