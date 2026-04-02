class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>result;
        for(int num:nums){
            int left=0;
            int right=result.size()-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(num>result[mid]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            if(left==result.size())result.push_back(num);
            else result[left]=num;
        }
        return result.size();
    }
};