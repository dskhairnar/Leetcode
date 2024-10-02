class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};  // Return empty vector if the input array is empty
        
        vector<int> sortedArr = arr;  // Make a copy of the original array
        sort(sortedArr.begin(), sortedArr.end());  // Sort the copied array

        // Create a hash map to store the rank of each unique element
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        // Assign ranks to unique elements in the sorted array
        for (int i = 0; i < sortedArr.size(); ++i) {
            if (rankMap.find(sortedArr[i]) == rankMap.end()) {
                rankMap[sortedArr[i]] = rank;
                rank++;  // Only increment the rank for unique elements
            }
        }
        
        // Create the result array by replacing each element with its rank
        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result[i] = rankMap[arr[i]];  // Assign the rank from the hash map
        }
        
        return result;
    }
};
