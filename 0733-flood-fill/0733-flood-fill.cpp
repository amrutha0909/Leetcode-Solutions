class Solution {
public:
    int n,m;
    void dfs(int sr,int sc,int color, int original,vector<vector<int>>&image,vector<vector<bool>>&visited){
        image[sr][sc]=color;
        visited[sr][sc]=true;
        
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=sr+dX[i];
            int ny=sc+dY[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&image[nx][ny]==original){
                dfs(nx,ny,color,original,image,visited);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size(),m=image[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        dfs(sr,sc,color,image[sr][sc],image,visited);
        return image;
    }
};