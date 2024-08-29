class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_map<int,int>mx,my;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    mx[i]++;my[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mx.find(i)!=mx.end()) matrix[i][j]=0;
                else if(my.find(j)!=my.end()) matrix[i][j]=0;
            }
        }
    }
};