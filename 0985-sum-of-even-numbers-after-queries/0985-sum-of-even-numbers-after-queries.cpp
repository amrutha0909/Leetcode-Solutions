class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int sum=0;
        for(int num:nums)if(num%2==0)sum+=num;
        for(auto query:queries){
            int val=query[0];
            int index=query[1];
            int old=nums[index];
            nums[index]+=val;
            if(nums[index]%2==0 && old%2==0)sum+=nums[index]-old;
            else if(nums[index]%2==0 && old%2!=0)sum+=nums[index];
            else if(nums[index]%2!=0 && old%2==0)sum-=old;
            ans.push_back(sum);
        }
        return ans;
    }
};