class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>&board,vector<vector<bool>>&visited){
        int n=board.size();
        int m=board[0].size();
        visited[x][y]=true;
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dX[i];
            int ny=y+dY[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&board[nx][ny]=='O'){
                dfs(nx,ny,board,visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,visited);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,visited);
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(0,j,board,visited);
            }
            if(board[n-1][j]=='O'){
                dfs(n-1,j,board,visited);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};