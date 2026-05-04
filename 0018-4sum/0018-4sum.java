class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        int n=nums.length;
        List<List<Integer>>res=new ArrayList<>();
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            long t=(long)target-nums[i];
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int left=j+1;
                int right=n-1;
                while(left<right){
                    long sum=(long)nums[j]+nums[left]+nums[right];
                    if(sum==t){
                        List<Integer>ans=new ArrayList<>();
                        ans.add(nums[i]);
                        ans.add(nums[j]);
                        ans.add(nums[left]);
                        ans.add(nums[right]);
                        res.add(ans);
                        left++;
                        right--;
                        while(left<right && nums[left]==nums[left-1])left++;
                        while(left<right && nums[right]==nums[right+1])right--;
                    }
                    else if(sum>t)right--;
                    else left++;
                }
            }
        }
        return res;
    }
}