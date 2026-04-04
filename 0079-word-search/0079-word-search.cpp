class Solution {
public:
    bool dfs(int i,int j,int index,vector<vector<char>>&board,string word,vector<vector<bool>>&visited){
        visited[i][j]=true;
        if(index==word.size())return true;
        int n=board.size();
        int m=board[0].size();
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx=i+dX[k];
            int ny=j+dY[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&board[nx][ny]==word[index]){
                if(dfs(nx,ny,index+1,board,word,visited))return true;
            }
        }
        visited[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]&&!visited[i][j]){
                    if(word.size()==1)return true;
                    if(dfs(i,j,1,board,word,visited))return true;
                }
            }
        }
        return false;
    }
};