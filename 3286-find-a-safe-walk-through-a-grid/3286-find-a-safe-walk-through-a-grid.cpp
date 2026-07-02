class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(),m=grid[0].size();
        health-=grid[0][0];
        if(health<=0)return false;
        queue<vector<int>>q;
        q.push({0,0,health});
        vector<vector<int>>best(n,vector<int>(m,-1));
        best[0][0]=health;
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();q.pop();
            int i=it[0];
            int j=it[1];
            int h=it[2];
            if(h<=0)continue;
            if(i==n-1&&j==m-1)return true;
            for(int k=0;k<4;k++){
                int nx=i+dX[k];
                int ny=j+dY[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                int newHealth=h-grid[nx][ny];
                if(newHealth<=0)continue;
                if(newHealth>best[nx][ny]){
                    best[nx][ny]=newHealth;
                    q.push({nx,ny,newHealth});
                }
            }
        }
        return false;
    }
};