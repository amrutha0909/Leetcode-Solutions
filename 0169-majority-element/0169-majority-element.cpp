class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int major=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                major=nums[i];
                count++;
            }
            else if(nums[i]!=major){
                major=nums[i];
                count=1;
            }
        }
        return major;
    }
};