class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> val(n, vector<int>(m));
        vector<vector<int>> present(n, vector<int>(m));

        // Build grids
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') {
                    val[i][j] = 1;
                    present[i][j] = 1;
                } 
                else if(grid[i][j] == 'Y') {
                    val[i][j] = -1;
                    present[i][j] = 1;
                } 
                else {
                    val[i][j] = 0;
                    present[i][j] = 0;
                }
            }
        }

        int count = 0;

        // Only (0,0) → (i,j)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // build prefix
                if(i > 0) {
                    val[i][j] += val[i-1][j];
                    present[i][j] += present[i-1][j];
                }
                if(j > 0) {
                    val[i][j] += val[i][j-1];
                    present[i][j] += present[i][j-1];
                }
                if(i > 0 && j > 0) {
                    val[i][j] -= val[i-1][j-1];
                    present[i][j] -= present[i-1][j-1];
                }

                // check condition
                if(val[i][j] == 0 && present[i][j] > 0) {
                    count++;
                }
            }
        }

        return count;
    }
};