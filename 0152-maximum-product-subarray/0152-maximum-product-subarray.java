class Solution {
    public int maxProduct(int[] nums) {
        int minSoFar=nums[0];
        int maxSoFar=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.length;i++){
            int curr=nums[i];
            int tempMax=Math.max(curr,Math.max(minSoFar*curr,maxSoFar*curr));
            minSoFar=Math.min(curr,Math.min(minSoFar*curr,maxSoFar*curr));
            maxSoFar=tempMax;
            ans=Math.max(ans,maxSoFar);
        }
        return ans;
    }
}