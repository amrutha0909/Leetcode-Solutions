class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n=nums.size();
            /*int count=0;
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    count++;
                }
            }
            while(count--){
                for(int i=0;i<n-1;i++){
                    if(nums[i]==0){
                        swap(nums[i],nums[(i+1)]);
                    }
                }
            }
        }*/
        int non=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                if(i!=non){
                    swap(nums[i],nums[non]);
                }
                non++;
            }
        }
        }
    };