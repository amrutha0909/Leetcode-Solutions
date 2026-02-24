class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int r, int c, int color, int newColor){
        ans[r][c]=newColor;
        int n=image.size();
        int m=image[0].size();
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=r+dX[i];
            int ny=c+dY[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==color && ans[nx][ny]!=newColor){
                dfs(image,ans,nx,ny,color,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int col=image[sr][sc];
        dfs(image,ans,sr,sc,col,color);
        return ans;
    }
};