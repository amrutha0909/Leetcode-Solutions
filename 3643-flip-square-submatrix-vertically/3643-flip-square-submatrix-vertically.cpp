class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j=y;j<y+k;j++){
            stack<int>ans;
            for(int i=x;i<x+k;i++){
                ans.push(grid[i][j]);
            }
            for(int i=x;i<x+k&&!ans.empty();i++){
                grid[i][j]=ans.top();
                ans.pop();
            }
        }
        return grid;
        
    }
};