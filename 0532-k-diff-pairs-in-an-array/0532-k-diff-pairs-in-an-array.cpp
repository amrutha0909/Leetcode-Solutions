class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>mpp;
        for(int num:nums){
            mpp[num]++;
        }
        for(auto&it:mpp){
            int key=it.first;
            if(k==0){
                if(it.second>1)count++;
            }
            else if(mpp.find(k+key)!=mpp.end())count++;
        }
        return count;
    }
};