class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0;
        int count=0;
        int product=1;
        for(int right=0;right<nums.size();right++){
            product*=nums[right];
            while(product>=k &&left<nums.size()){
                product=product/nums[left];
                left++;
            }
            if(product<k)count+=right-left+1;
        }
        return count;
    }
};