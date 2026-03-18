class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2&&!visited[i][j]){
                    q.push({i,j});
                }
            }
        }
        int minutes=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                visited[x][y]=true;
                vector<int>dX={-1,0,1,0};
                vector<int>dY={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nx=x+dX[i];
                    int ny=y+dY[i];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            if(!q.empty())minutes++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return minutes;
    }
};