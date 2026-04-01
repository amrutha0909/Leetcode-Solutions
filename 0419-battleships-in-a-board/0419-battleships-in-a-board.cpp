class Solution {
public:
    void h_dfs(int i,int j,vector<vector<char>>&board,vector<vector<bool>>&visited){
        int n=board.size(),m=board[0].size();
        visited[i][j]=true;
        vector<int>dX={-1,1};
        vector<int>dY={0,0};
        for(int k=0;k<2;k++){
            int nx=i+dX[k];
            int ny=j+dY[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&board[nx][ny]=='X'){
                h_dfs(nx,ny,board,visited);
            }
        }
    }
    void v_dfs(int i,int j,vector<vector<char>>&board,vector<vector<bool>>&visited){
        int n=board.size(),m=board[0].size();
        visited[i][j]=true;
        vector<int>dY={-1,1};
        vector<int>dX={0,0};
        for(int k=0;k<2;k++){
            int nx=i+dX[k];
            int ny=j+dY[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&board[nx][ny]=='X'){
                v_dfs(nx,ny,board,visited);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='X'){
                    if((i>0&&board[i-1][j]=='X'&&!visited[i-1][j])||(i<n-1&&board[i+1][j]=='X'&&!visited[i+1][j])){
                        count++;
                        h_dfs(i,j,board,visited);
                    }
                    else if((j>0&&board[i][j-1]=='X'&&!visited[i][j-1])||(j<m-1&&board[i][j+1]=='X'&&!visited[i][j+1])){
                        count++;
                        v_dfs(i,j,board,visited);
                    }
                    else{
                        count++;
                    }
                }
            }
        }
        return count;
    }
};