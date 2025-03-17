class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            int n=nums.size();
            vector<int>hash(1001,0);
            for(int i=0;i<n;i++){
                hash[nums[i]]++;
            }
            for(int i=0;i<hash.size();i++){
                if(hash[i]%2!=0){
                    return false;
                }
            }
            return true;
        }
    };