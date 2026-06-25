class Solution {
public: 
    vector<int>dX={-1,0,1,0};
    vector<int>dY={0,1,0,-1};
    void dfs(int x,int y,vector<vector<char>>&board,vector<vector<bool>>&visited){
        int n=board.size();
        int m=board[0].size();
        visited[x][y]=true;
        board[x][y]='X';
        for(int i=0;i<4;i++){
            int nx=x+dX[i];
            int ny=y+dY[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&board[nx][ny]=='O'){
                dfs(nx,ny,board,visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board[0].size();
        int n=board.size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            visited[i][0]=true;
        }
        for(int i=0;i<m;i++){
            visited[0][i]=true;
        }
        for(int i=0;i<n;i++){
            visited[i][m-1]=true;
        }
        for(int i=0;i<m;i++){
            visited[n-1][i]=true;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O')dfs(i,j,board,visited);
            }
        }
    }
};