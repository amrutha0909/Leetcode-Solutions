class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    visited[i][j]=true;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int steps=it.second;
            vector<int>dX={-1,0,1,0};
            vector<int>dY={0,1,0,-1};
            dist[x][y]=steps;
            for(int i=0;i<4;i++){
                int nx=x+dX[i];
                int ny=y+dY[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&!visited[nx][ny]){
                    visited[nx][ny]=true;
                    q.push({{nx,ny},steps+1});
                }
            }
        }
        return dist;
    }
};