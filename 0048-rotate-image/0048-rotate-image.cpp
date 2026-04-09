class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>ans(n);
        int r=0;
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
                ans[r].push_back(matrix[i][j]);
            }
            r++;
        }
        matrix=ans;
    }
};