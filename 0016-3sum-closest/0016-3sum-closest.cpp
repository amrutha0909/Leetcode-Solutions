class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minDiff=INT_MAX;
        int minSum=0;
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                int diff=abs(target-sum);
                if(diff<minDiff){
                    minDiff=diff;
                    minSum=sum;
                }
                else if(sum>target){
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