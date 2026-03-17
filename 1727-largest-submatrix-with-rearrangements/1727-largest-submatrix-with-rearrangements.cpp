class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(matrix[row][col]!=0 && row>0){
                    matrix[row][col]+=matrix[row-1][col];
                }
            }
            vector<int>currRow=matrix[row];
            sort(currRow.begin(),currRow.end(),greater());
            for(int i=0;i<m;i++){
                ans=max(ans,currRow[i]*(i+1));
            }
        }
        return ans;
    }
};