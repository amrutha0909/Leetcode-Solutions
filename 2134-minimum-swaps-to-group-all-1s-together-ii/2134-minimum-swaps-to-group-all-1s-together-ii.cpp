class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int num:nums)total+=num;
        int curr=0;
        for(int i=0;i<total;i++){
            curr+=nums[i];
        }
        int ans=total;
        ans=min(ans,total-curr);
        for(int i=1;i<n;i++){
            curr-=nums[(i-1)%n];
            curr+=nums[(i+total-1)%n];
            ans=min(ans,total-curr);
        }
        return ans;
    }
};