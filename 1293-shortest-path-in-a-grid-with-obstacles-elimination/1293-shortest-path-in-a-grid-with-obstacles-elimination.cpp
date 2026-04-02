class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>>visited(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        queue<vector<int>>q;
        q.push({0,k,0,0});
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                auto it=q.front();
                q.pop();
                int dist=it[0];
                int obs=it[1];
                int x=it[2];
                int y=it[3];
                vector<int>dX={-1,0,1,0};
                vector<int>dY={0,1,0,-1};
                if(x==n-1&&y==m-1)return dist;
                visited[x][y][obs]=true;
                for(int i=0;i<4;i++){
                    int nx=x+dX[i];
                    int ny=y+dY[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        int curr_obs=grid[nx][ny]==1?1:0;
                        int next_k=obs-curr_obs;
                        if(next_k>=0&&!visited[nx][ny][next_k]){
                            q.push({dist+1,next_k,nx,ny});
                        }
                    }
                }
            }
        }
        return -1;
    }
};