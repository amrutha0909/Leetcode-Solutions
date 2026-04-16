class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //make 2 queues and visited vectors for pacific and atlantic
        //perform bfs on atlantic sides bottom row and right column. and pacific sides top row and left column
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>>paciVis(n,vector<bool>(m,false));
        vector<vector<bool>>atlaVis(n,vector<bool>(m,false));
        queue<pair<int,int>>p;
        queue<pair<int,int>>a;
        for(int i=0;i<n;i++){
            paciVis[i][0]=true;
            p.push({i,0});
        }
        for(int i=0;i<n;i++){
            atlaVis[i][m-1]=true;
            a.push({i,m-1});
        }
        for(int j=0;j<m;j++){
            paciVis[0][j]=true;
            p.push({0,j});
        }
        for(int j=0;j<m;j++){
            atlaVis[n-1][j]=true;
            a.push({n-1,j});
        }
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        while(!p.empty()){
            int len=p.size();
            for(int k=0;k<len;k++){
                auto it=p.front();p.pop();
                int x=it.first;
                int y=it.second;
                for(int i=0;i<4;i++){
                    int nx=x+dX[i];
                    int ny=y+dY[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && heights[nx][ny]>=heights[x][y] && !paciVis[nx][ny]){
                        paciVis[nx][ny]=true;
                        p.push({nx,ny});
                    }
                }
            }
            
        }
        while(!a.empty()){
            int len=a.size();
            for(int k=0;k<len;k++){
                auto it=a.front();a.pop();
                int x=it.first;
                int y=it.second;
                for(int i=0;i<4;i++){
                    int nx=x+dX[i];
                    int ny=y+dY[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && heights[nx][ny]>=heights[x][y] && !atlaVis[nx][ny]){
                        atlaVis[nx][ny]=true;
                        a.push({nx,ny});
                    }
                }
            }
            
        }
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paciVis[i][j] && atlaVis[i][j])result.push_back({i,j});
            }
        }
        return result;
    }
};