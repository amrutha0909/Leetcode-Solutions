class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long>rowSums;
        vector<long long>colSums;
        long long totalRow=0;
        for(int i=0;i<grid.size();i++){
            long long sum=0;
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
            totalRow+=sum;
            rowSums.push_back(sum);
        }
        long long totalCol=0;
        for(int j=0;j<grid[0].size();j++){
            long long sum=0;
            for(int i=0;i<grid.size();i++){
                sum+=grid[i][j];
            }
            totalCol+=sum;
            colSums.push_back(sum);
        }
        if(totalRow%2!=0)return false;
        long long target=totalRow/2;
        long long curr=0;
        for(int i=0;i<rowSums.size();i++){
            curr+=rowSums[i];
            if(curr==target)return true;
        }
        curr=0;
        for(int i=0;i<colSums.size();i++){
            curr+=colSums[i];
            if(curr==target)return true;
        }
        return false;
    }
};