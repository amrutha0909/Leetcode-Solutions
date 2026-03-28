class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>>visited(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        queue<vector<int>>q;
        q.push({0,0,k,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it[0];
            int y=it[1];
            int stops=it[2];
            int dist=it[3];
            vector<int>dX={-1,0,1,0};
            vector<int>dY={0,1,0,-1};
            visited[x][y][stops]=true;
            if(x==n-1&&y==m-1)return dist;
            for(int i=0;i<4;i++){
                int nx=x+dX[i];
                int ny=y+dY[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    int curr_stops=grid[nx][ny]==1?1:0;
                    int next_k=stops-curr_stops;
                    if(next_k>=0&&!visited[nx][ny][next_k]){
                        visited[nx][ny][stops-curr_stops]=true;
                        q.push({nx,ny,next_k,dist+1});
                    }
                }
            }
        }
        return -1;
    }
};