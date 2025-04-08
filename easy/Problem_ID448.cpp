class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            vector<int>ans;
            vector<int>hash(100001,0);
            for(int i=0;i<nums.size();i++){
                hash[nums[i]]++;
            }
            for(int i=1;i<=nums.size();i++){
                if(hash[i]==0){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };