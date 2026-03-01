class Solution {
public:
    int helper(vector<int>& nums, int k){
        unordered_map<int,int>mpp;
        int count=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)mpp.erase(nums[left]);
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return helper(nums,k)-helper(nums,k-1);
    }
};