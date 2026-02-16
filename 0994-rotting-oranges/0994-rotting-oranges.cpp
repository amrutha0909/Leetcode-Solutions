class Solution {
public:
    void bfs(vector<vector<int>>&grid, queue<pair<int,int>>&q, int&min, vector<int>&delRow, vector<int>&delCol){
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                for(int i=0;i<4;i++){
                    int nx=delRow[i]+x;
                    int ny=delCol[i]+y;
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                    }
                }   
            }
            if(!q.empty()){
                min++;
            }
        }   
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int min=0;
        vector<int>delRow={-1,0,1,0};
        vector<int>delCol={0,1,0,-1};
        bfs(grid,q,min,delRow,delCol);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return min;
    }
};