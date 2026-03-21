class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        if(grid[0][0]!=0||grid[n-1][m-1]!=0)return -1;
        visited[0][0]=true;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int steps=it.second;
            if(x==n-1&&y==m-1)return steps;
            vector<int>dX={-1,0,1,0,-1,1,-1,1};
            vector<int>dY={0,1,0,-1,-1,1,1,-1};
            for(int i=0;i<8;i++){
                int nx=x+dX[i];
                int ny=y+dY[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&grid[nx][ny]==0){
                    visited[nx][ny]=true;
                    q.push({{nx,ny},steps+1});
                }
            }
        }
        return -1;
    }
};