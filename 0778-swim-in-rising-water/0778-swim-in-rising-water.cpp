class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Priority queue: {current_max_elevation, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        vector<int> dX = {-1, 0, 1, 0};
        vector<int> dY = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int currMax = it[0];
            int x = it[1];
            int y = it[2];

            if (visited[x][y]) continue;
            visited[x][y] = true;

            // Reached destination
            if (x == n - 1 && y == n - 1) return currMax;

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int nx = x + dX[i];
                int ny = y + dY[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    int newMax = max(currMax, grid[nx][ny]);
                    if (newMax < dist[nx][ny]) {
                        dist[nx][ny] = newMax;
                        pq.push({newMax, nx, ny});
                    }
                }
            }
        }

        return -1; // unreachable, should never happen
    }
};