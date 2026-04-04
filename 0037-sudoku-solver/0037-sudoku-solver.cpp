class Solution {
public:
    bool solved=false;
    int n=3,N=9;
    bool rows[10][9]={};
    bool cols[10][9]={};
    bool boxes[10][9]={};
    void fill(int i, int j,int d,vector<vector<char>>&board){
        board[i][j]=d+'0';
        int n=board.size(),m=board[0].size();
        int index=(i/3)*3+(j/3);
        boxes[d][index]=true;
        rows[d][i]=true;
        cols[d][j]=true;
    }
    bool isValid(int i, int j,int d){
        int index=(i/3)*3+(j/3);
        if(boxes[d][index]||rows[d][i]||cols[d][j])return false;
        return true;
    }
    void remove(int i, int j,int d,vector<vector<char>>&board){
        int n=board.size(),m=board[0].size();
        int index=(i/3)*3+(j/3);
        board[i][j]='.';
        boxes[d][index]=false;
        rows[d][i]=false;
        cols[d][j]=false;
    }
    void backtrack(int i,int j,vector<vector<char>>&board){
        if(i==N){
            solved=true;
            return;
        }
        int nextRow=(j==N-1)?i+1:i;
        int nextCol=(j==N-1)?0:j+1;
        if(board[i][j]=='.'){
            for(int d=1;d<=9;d++){
                if(isValid(i,j,d)){
                    fill(i,j,d,board);
                    backtrack(nextRow,nextCol,board);
                    if(solved)return;
                    remove(i,j,d,board);
                }
            }
        }
        else{
            backtrack(nextRow,nextCol,board);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]!='.'){
                    fill(i,j,board[i][j]-'0',board);
                }
            }
        }
        backtrack(0,0,board);
    }
};