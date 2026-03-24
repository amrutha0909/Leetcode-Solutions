class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        const int MOD=12345;
        long long totalProduct=1;
        vector<vector<int>>suffixProduct(n,vector<int>(m));
        long long suffix=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suffixProduct[i][j]=suffix;
                suffix=suffix*grid[i][j]%MOD;
            }
        }
        long long prefix=1;
        vector<vector<int>>prefixProduct(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                suffixProduct[i][j]=prefix*suffixProduct[i][j]%MOD;
                prefix=prefix*grid[i][j]%MOD;
            }
        }
        return suffixProduct;
    }
};