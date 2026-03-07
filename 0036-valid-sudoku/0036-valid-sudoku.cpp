class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>>boxes(9,vector<bool>(9,false));
        vector<vector<bool>>rows(9,vector<bool>(9,false));
        vector<vector<bool>>cols(9,vector<bool>(9,false));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'1';
                    int idx=(i/3)*3+(j/3);
                    if(rows[i][num]||cols[j][num]||boxes[idx][num])return false;
                    rows[i][num]=cols[j][num]=boxes[idx][num]=true;
                }
            }
        }
        return true;
    }
};