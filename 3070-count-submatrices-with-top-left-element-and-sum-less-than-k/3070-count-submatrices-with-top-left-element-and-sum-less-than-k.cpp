class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]>k)return 0;
        int count=1;
        for(int j=1;j<m;j++){
            grid[0][j]+=grid[0][j-1];
            if(grid[0][j]<=k)count++;
        }
        vector<vector<int>>dup=grid;
        for(int i=1;i<n;i++){
            dup[i][0]+=dup[i-1][0];
            if(dup[i][0]<=k)count++;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){ 
                if(grid[i][j]+grid[i-1][j]<=k){
                    count++;
                }
                grid[i][j]+=grid[i-1][j];
            }
        }
        return count;
    }
};