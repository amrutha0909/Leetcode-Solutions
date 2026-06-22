class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto query:queries){
            int val=query[0];
            int index=query[1];
            nums[index]+=val;
            int sum=0;
            for(int num:nums)if(num%2==0)sum+=num;
            ans.push_back(sum);
        }
        return ans;
    }
};