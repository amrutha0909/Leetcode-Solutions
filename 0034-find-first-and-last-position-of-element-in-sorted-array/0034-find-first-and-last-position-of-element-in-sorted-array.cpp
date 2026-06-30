class Solution {
public:
    int upperBound(vector<int>&nums, int target, int low, int high, int ans){
        if(low>high)return ans;
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
            return upperBound(nums,target,mid+1,high,ans);
        }
        else if(nums[mid]>target){
            return upperBound(nums,target,low,mid-1,ans);
        }
        else{
            return upperBound(nums,target,mid+1,high,ans);
        }
    }
    int lowerBound(vector<int>&nums, int target, int low, int high, int ans){
        if(low>high)return ans;
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
            return lowerBound(nums,target,low,mid-1,ans);
        }
        else if(nums[mid]>target){
            return lowerBound(nums,target,low,mid-1,ans);
        }
        else{
            return lowerBound(nums,target,mid+1,high,ans);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=lowerBound(nums,target,0,n-1,-1);
        int h=upperBound(nums,target,0,n-1,-1);
        return {l,h};
    }
};