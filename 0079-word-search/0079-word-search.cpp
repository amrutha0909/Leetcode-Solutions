class Solution {
public:
    bool backtrack(int i, int j, vector<vector<char>>&board, string&word, int index){
        int n=board.size();
        int m=board[0].size();
        if(index==word.size())return true;
        if(i>=n||i<0||j>=m||j<0||board[i][j]!=word[index]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        bool found=backtrack(i+1,j,board,word,index+1)||backtrack(i,j+1,board,word,index+1)||backtrack(i-1,j,board,word,index+1)||backtrack(i,j-1,board,word,index+1);
        board[i][j]=temp; 
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtrack(i,j,board,word,0))return true;
            }
        }
        return false;
    }
};