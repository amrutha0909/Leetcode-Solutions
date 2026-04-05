class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum=0;
        int count=0;
        unordered_map<int,int>prefixCount;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            if(prefixSum==k)count++;
            if(prefixCount.find(prefixSum-k)!=prefixCount.end()){
                count+=prefixCount[prefixSum-k];
            }
            prefixCount[prefixSum]++;
        }
        return count;
    }
};