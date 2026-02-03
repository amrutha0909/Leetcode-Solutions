class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0;
        while(i+1<nums.size()&&nums[i+1]>nums[i]){    
            i++;
        }

        int j=i;
        if(j==0)return false;
        if(j>=nums.size())return false;
        while(j+1<nums.size()&&nums[j+1]<nums[j]){
            j++;
        }
        int k=j;
        while(k+1<nums.size()&&nums[k+1]>nums[k]){
            k++;
        }
        if(k!=nums.size()-1)return false;
        if(i<j && j<k)return true;
        return false;
    }
};