class Solution {
public:
    bool backtrack(int i, int j, int index, vector<vector<char>>&board, string word){
        if(index==word.size())return true;
        int n=board.size();
        int m=board[0].size();
        if(i<0||i>=n||j<0||j>=m||board[i][j]!=word[index])return false;
        char temp=board[i][j];
        board[i][j]='#';
        bool found=backtrack(i+1,j,index+1,board,word)||backtrack(i,j+1,index+1,board,word)||backtrack(i-1,j,index+1,board,word)||backtrack(i,j-1,index+1,board,word);
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(backtrack(i,j,0,board,word))return true;
            }
        }
        return false;
    }
};