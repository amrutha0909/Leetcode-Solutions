class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer>mpp=new HashMap<>();
        int left=0;
        int maxLen=0;
        for(int right=0;right<s.length();right++){
            mpp.put(s.charAt(right),mpp.getOrDefault(s.charAt(right),0)+1);
            while(mpp.get(s.charAt(right))>1){
                mpp.put(s.charAt(left),mpp.get(s.charAt(left))-1);
                if(mpp.get(s.charAt(left))==0){
                    mpp.remove(s.charAt(left));
                }
                left++;
            }
            maxLen=Math.max(maxLen,right-left+1);
        }
        return maxLen;
    }
}