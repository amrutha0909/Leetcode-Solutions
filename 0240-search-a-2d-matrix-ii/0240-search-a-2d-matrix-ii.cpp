class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=m-1;
        while(true){
            int curr=matrix[i][j];
            if(curr==target)return true;
            if(curr>target){
                j--;
                if(j<0)break;
            }
            else if(curr<target){
                i++;
                if(i>n-1)break;
            }

        }
        return false;
    }
};