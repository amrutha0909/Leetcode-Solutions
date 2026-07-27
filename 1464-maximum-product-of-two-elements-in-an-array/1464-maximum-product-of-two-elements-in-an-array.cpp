class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            ans=max(ans,(nums[i]-1)*(nums[i+1]-1));
        }
        return ans;
    }
};