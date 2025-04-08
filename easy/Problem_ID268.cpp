class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int sum1=0;
            int sum2=0;
            for(int i=0;i<=nums.size();i++){
                sum1+=i;
            }
            for(int i=0;i<nums.size();i++){
                sum2+=nums[i];
            }
            if(sum1!=sum2){
                return abs(sum1-sum2);
            }
            return 0;
        }
    };