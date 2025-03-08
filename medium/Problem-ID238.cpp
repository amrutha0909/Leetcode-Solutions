class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n=nums.size();
            vector<int>answer(n,0);
            int prod=1;
            int count=0;
            for(int i=0;i<n;i++){
                if(nums[i]!=0){
                    prod*=nums[i];
                }
                else{
                    count++;
                }
            }
            if(count>1){
                return answer;
            }
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    answer[i]=prod;
                }
                else if(count==0){
                    answer[i]=prod/nums[i];
                }
            }
            return answer;
        }
    };