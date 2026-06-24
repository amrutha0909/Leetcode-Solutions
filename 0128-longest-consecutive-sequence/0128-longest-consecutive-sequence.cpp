class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int>s(nums.begin(),nums.end());
        for(int num:s){
            if(s.count(num-1)==0){
                int curr=num;
                int count=1;
                while(s.count(curr+1)){
                    curr++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};