class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int j=i+1;
            int right=nums.size()-1;
            while(j<right){
                if(nums[i]+nums[j]+nums[right]>0)right--;
                else if(nums[i]+nums[j]+nums[right]<0){
                    j++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[right]});
                    while(j<right&&nums[j]==nums[j+1])j++;
                    while(j<right&&nums[right]==nums[right-1])right--;
                    j++;
                    right--;
                } 
            }
        }
        return ans;
    }
};