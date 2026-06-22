class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[j-2]){
                nums[j]=nums[i];
                j++;
            }
        }
        return nums.size() <= 2 ? nums.size() : j;
    }
};