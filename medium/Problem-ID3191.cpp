class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n=nums.size();
            int count=0;
            for(int i=0;i<n;i++){
                if(nums[i]==0&&(i+3)<=n){
                    for(int j=i;j<min(n,i+3);j++){
                        if(nums[j]==0){
                            nums[j]=1;
                        }
                        else{
                            nums[j]=0;
                        }
                    }
                    count++;
                }
            }
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    return -1;
                }
            }
            return count;
        }
    };