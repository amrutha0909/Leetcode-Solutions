class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int num:nums){
            total+=num;
        }
        if(total%2!=0)return false;
        int target=total/2;
        unordered_set<int>possibleSums={0};
        for(int num:nums){
            unordered_set<int>newSum=possibleSums;
            for(int s:possibleSums){
                if(num+s==target)return true;
                newSum.insert(s+num);
            }
            possibleSums=newSum;
        }
        return possibleSums.count(target)>0;
    }
};