class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int s=matrix.size();
            int n=matrix[0].size();
            if(s==1){
                    for(int i=0;i<n;i++){
                        if(matrix[0][i]==target){
                            return true;
                        }
                    }
                }        
            for(int i=0;i<s;i++){          
                int left=0;
                int right=n-1;
                while(left<=right){
                    int mid=left+(right-left)/2;
                    if(target==matrix[i][mid]){
                        return true;
                    }
                    if(target<matrix[i][mid]){
                        right=mid-1;
                    }
                    if(target>matrix[i][mid]){
                        left=mid+1;
                    }
                }
            }
            return false;
        }
    };