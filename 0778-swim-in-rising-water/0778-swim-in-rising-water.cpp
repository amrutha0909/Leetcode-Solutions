class Solution {
public:
    bool canReach(int t, int n,vector<vector<int>>&grid){
        // BFS to check if (n-1,n-1) is reachable with max elevation <= t
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        queue<pair<int,int>> q;
        if(grid[0][0] > t) return false; // can't start yet
        q.push({0,0});
        visited[0][0] = true;
        
        vector<int> dX = {-1,0,1,0};
        vector<int> dY = {0,1,0,-1};
            
        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            if(x==n-1 && y==n-1) return true; // reached end
            for(int i=0;i<4;i++) {
                int nx = x + dX[i];
                int ny = y + dY[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n 
                    && !visited[nx][ny] && grid[nx][ny]<=t) {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int lo = grid[0][0];
        int hi = 0;
        
        // Find the maximum elevation in the grid
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                hi = max(hi, grid[i][j]);
        
        // Binary search on the minimum maximum elevation
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(canReach(mid,n,grid)) hi = mid;   // try smaller max
            else lo = mid + 1;             // need higher max
        }
        
        return lo; // minimum time to reach bottom-right
    }
};