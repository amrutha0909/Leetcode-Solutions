class Solution {
public:
    int n=3,N=9;
    int boxes[9][10]={},rows[9][10]={},cols[9][10]={};
    bool isSolved=false;
    void placeNumber(int d,int row, int col, vector<vector<char>>&board){
        int idx=(row/n)*n+(col/n);
        boxes[idx][d]++;
        rows[row][d]++;
        cols[col][d]++;
        board[row][col]=d+'0';
    }
    void removeNumber(int d,int row, int col, vector<vector<char>>&board){
        int idx=(row/n)*n+(col/n);
        boxes[idx][d]--;
        rows[row][d]--;
        cols[col][d]--;
        board[row][col]='.';
    }
    bool couldPlace(int d,int row, int col, vector<vector<char>>&board){
        int idx=(row/n)*n+(col/n);
        return rows[row][d]+cols[col][d]+boxes[idx][d]==0;
    }
    void backtrack(int row, int col, vector<vector<char>>&board){
        if(row==N){
            isSolved=true;
            return;
        }
        int nextRow=(col==N-1)?row+1:row;
        int nextCol=(col==N-1)?0:col+1;
        if(board[row][col]=='.'){
            for(int d=1;d<=9;d++){
                if(couldPlace(d,row,col,board)){
                    placeNumber(d,row,col,board);
                    backtrack(nextRow,nextCol,board);
                    if(isSolved)return;
                    removeNumber(d,row,col,board);
                }
            }
        }else{
            backtrack(nextRow,nextCol,board);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]!='.'){
                    placeNumber(board[i][j]-'0',i,j,board);
                }
            }
        }
        backtrack(0,0,board);
    }
};