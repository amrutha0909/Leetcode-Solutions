class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int col=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        image[sr][sc]=color;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vis[sr][sc]=true;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            vector<int>dX={-1,0,1,0};
            vector<int>dY={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nx=x+dX[i];
                int ny=y+dY[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&image[nx][ny]==col&&!vis[nx][ny]){
                    vis[nx][ny]=true;
                    image[nx][ny]=color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
};