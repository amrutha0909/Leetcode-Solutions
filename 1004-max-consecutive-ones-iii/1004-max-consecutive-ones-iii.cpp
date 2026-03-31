class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0;
        int maxFreq=0;
        unordered_map<int,int>mpp;
        int left=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==1)mpp[nums[right]]++;
            maxFreq=max(maxFreq,mpp[nums[right]]);
            while(right-left+1-maxFreq>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)mpp.erase(nums[left]);
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};