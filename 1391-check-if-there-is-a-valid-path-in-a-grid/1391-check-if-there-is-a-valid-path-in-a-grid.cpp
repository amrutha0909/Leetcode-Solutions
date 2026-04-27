class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // directions: up, right, down, left
        vector<vector<vector<int>>> dirs = {
            {},
            {{0,1},{0,-1}},   // 1: left-right
            {{1,0},{-1,0}},   // 2: up-down
            {{0,-1},{1,0}},   // 3
            {{0,1},{1,0}},    // 4
            {{0,-1},{-1,0}},  // 5
            {{0,1},{-1,0}}    // 6
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m,false));

        q.push({0,0});

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();

            if(x==n-1 && y==m-1) return true;
            if(vis[x][y]) continue;
            vis[x][y] = true;

            for(auto &d : dirs[grid[x][y]]) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]) {

                    // check reverse connection
                    for(auto &back : dirs[grid[nx][ny]]) {
                        if(nx + back[0] == x && ny + back[1] == y) {
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return false;
    }
};