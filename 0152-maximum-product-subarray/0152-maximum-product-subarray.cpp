class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minSoFar=nums[0];
        int maxSoFar=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int curr=nums[i];
            int tempMax=max(curr,max(minSoFar*curr,maxSoFar*curr));
            minSoFar=min(curr,min(minSoFar*curr,maxSoFar*curr));
            maxSoFar=tempMax;
            ans=max(ans,maxSoFar);
        }
        return ans;
    }
};