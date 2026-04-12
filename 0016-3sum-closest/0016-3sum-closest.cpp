class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minDiff=INT_MAX;
        int minSum=0;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                int diff=abs(target-sum);
                if(diff<minDiff){
                    minDiff=diff;
                    minSum=sum;
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1])left++;
                    while(left<right && nums[right]==nums[right+1])right--;
                }
                else if(diff>minDiff){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return minSum;
    }
};