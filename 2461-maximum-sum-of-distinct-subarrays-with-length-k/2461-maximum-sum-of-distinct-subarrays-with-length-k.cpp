class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int left=0;
        long long sum=0;
        long long maxSum=0;
        for(int right=0;right<nums.size();right++){
            mpp[nums[right]]++;
            sum+=nums[right];
            while(mpp[nums[right]]>1 || (right-left+1)>k){
                mpp[nums[left]]--;
                sum-=nums[left];
                if(mpp[nums[left]]==0)mpp.erase(nums[left]);
                left++;
            }
            if(right-left+1==k){
                maxSum=max(maxSum,sum);
            }
        }
        return maxSum;
    }
};