class Solution {
    public String minWindow(String s, String t) {
        int left=0;
        int[]minWindow=new int[2];
        minWindow[0]=0;
        minWindow[1]=Integer.MAX_VALUE;
        int target=t.length();
        Map<Character,Integer>mpp=new HashMap<>();
        for(char c:t.toCharArray()){
            mpp.put(c,mpp.getOrDefault(c,0)+1);
        }
        for(int right=0;right<s.length();right++){
            char c=s.charAt(right);
            if(mpp.containsKey(c)&& mpp.get(c)>0){
                target--;
            }
            mpp.put(c,mpp.getOrDefault(c,0)-1);
            if(target==0){                
                while(true){
                    char ch=s.charAt(left);
                    if(mpp.containsKey(ch) && mpp.get(ch)==0){
                        break;
                    }
                    mpp.put(ch,mpp.getOrDefault(ch,0)+1);
                    left++;
                }
                if(minWindow[1]-minWindow[0]>right-left){
                    minWindow[1]=right;
                    minWindow[0]=left;
                }
                mpp.put(s.charAt(left),mpp.getOrDefault(s.charAt(left),0)+1);
                left++;
                target++;
            }
        }
        if (minWindow[1] == Integer.MAX_VALUE) return "";
        return minWindow[1]>s.length()?"":s.substring(minWindow[0],minWindow[1]+1);
    }
}