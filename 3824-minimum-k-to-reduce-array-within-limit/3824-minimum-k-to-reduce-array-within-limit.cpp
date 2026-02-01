class Solution {
public:
    int minimumK(vector<int>& nums) {
        long long sum=0;
        for(int x:nums)sum+=x;
        int low=1;
        int high=1e9;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long ops=0;
            for(int x:nums){
                ops+=(x+mid-1)/mid;
                if(ops>1LL*mid*mid)break;
            }
            if(ops<=1LL*mid*mid){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};