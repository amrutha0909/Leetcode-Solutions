class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer>st=new HashSet<>();
        for(int num:nums)st.add(num);
        int maxLen=0;
        for(int num:nums){
            if(!st.contains(num-1)){
                int curr=num;
                int count=1;
                while(st.contains(curr+1)){
                    curr++;
                    count++;
                }
                maxLen=Math.max(maxLen,count);
            }
            
        }
        return maxLen;
    }
}