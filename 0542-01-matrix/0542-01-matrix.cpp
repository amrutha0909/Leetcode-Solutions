class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    visited[i][j]=true;
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int i=it.second.first;
            int j=it.second.second;
            dist[i][j]=d;
            vector<int>dX={-1,0,1,0};
            vector<int>dY={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nx=i+dX[k];
                int ny=j+dY[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]){
                    visited[nx][ny]=true;
                    q.push({d+1,{nx,ny}});
                }
            }
        }
        return dist;
    }
};