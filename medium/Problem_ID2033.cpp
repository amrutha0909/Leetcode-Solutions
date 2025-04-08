class Solution {
    public:
        double minOperations(vector<vector<int>>& grid, int x) {
    
            vector<int>gridd;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                gridd.push_back(grid[i][j]);
                }
            }
            sort(gridd.begin(),gridd.end());
            int n=gridd.size();
            int median=gridd[(n-1)/2];
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=abs(gridd[i]-median)/x;
                if ((abs(gridd[i] - median) % x) != 0) { return -1; }
            }
            return sum;
        }
    };