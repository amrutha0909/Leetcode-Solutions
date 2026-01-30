class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProduct=nums[0];
        int maxProduct=nums[0];
        int result=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int current=nums[i];
            int tempMax=max({current,minProduct*current,maxProduct*current});
            minProduct=min({current,current*minProduct,current*maxProduct});
            maxProduct=tempMax;
            result=max(result,maxProduct);
        }
        return result;
    }
};