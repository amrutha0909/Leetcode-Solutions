class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        vector<vector<int>>visited(n,vector<int>(m,false));
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int currMax=it[0];
            int x=it[1];
            int y=it[2];
            if(visited[x][y])continue;
            visited[x][y]=true;
            if(x==n-1 && y==m-1)return currMax;
            for(int i=0;i<4;i++){
                int nx=x+dX[i];
                int ny=y+dY[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
                    int newMax=max(grid[nx][ny],currMax);
                    if(newMax<dist[nx][ny]){
                        dist[nx][ny]=newMax;
                        pq.push({dist[nx][ny],nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};