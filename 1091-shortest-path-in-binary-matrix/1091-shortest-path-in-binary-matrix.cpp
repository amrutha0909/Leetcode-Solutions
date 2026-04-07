class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]!=0 ||grid[n-1][m-1]!=0)return -1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        q.push({1,{0,0}});
        vis[0][0]=true;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.second.first;
            int y=it.second.second;
            int dist=it.first;
            if(x==n-1&&y==m-1)return dist;
            vector<int>dX={-1,0,1,0,-1,-1,1,1};
            vector<int>dY={0,1,0,-1,1,-1,1,-1};
            for(int i=0;i<8;i++){
                int nx=x+dX[i];
                int ny=y+dY[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&grid[nx][ny]==0){
                    vis[nx][ny]=true;
                    q.push({dist+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};