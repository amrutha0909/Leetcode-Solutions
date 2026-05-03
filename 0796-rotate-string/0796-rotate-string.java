class Solution {
    public boolean rotateString(String s, String goal) {
        String d=s+s;
        if(s.length()!=goal.length())return false;
        return d.contains(goal);
    }
}