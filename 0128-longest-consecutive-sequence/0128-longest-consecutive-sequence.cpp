class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;
        for(int num:s){
            if(s.count(num-1)==0){
                int curr=num;
                int count=1;
                while(s.count(curr+1)){
                    count++;
                    curr++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};