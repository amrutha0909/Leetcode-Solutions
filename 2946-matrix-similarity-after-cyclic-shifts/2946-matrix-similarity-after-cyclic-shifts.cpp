class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        int r=k%m;
        vector<vector<int>>original=mat;
        vector<vector<int>>newMat(n,vector<int>(m));
        for(int i=0;i<r;i++){
            for(int x=0;x<n;x++){
                for(int y=0;y<m;y++){
                    newMat[x][y]=mat[x][(y+1)%m];
                }
            }
            mat=newMat;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(original[i][j]!=mat[i][j])return false;
            }
        }
        return true;
    }
};