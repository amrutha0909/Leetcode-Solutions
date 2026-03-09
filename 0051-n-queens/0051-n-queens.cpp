class Solution {
public:
    bool couldPlace(int row, int col, vector<string>&board,int n){
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q')return false;
        }
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q')return false;
        }
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    void backtrack(vector<string>&board,vector<vector<string>>&ans,int row,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(couldPlace(row,j,board,n)){
                board[row][j]='Q';
                backtrack(board,ans,row+1,n);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        backtrack(board,ans,0,n);
        return ans;
    }
};