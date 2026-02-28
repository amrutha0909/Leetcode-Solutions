class Solution {
public:
    int lengthOfLastWord(string s) {
        int right=s.size()-1;
        int left=0;
        while(left<=right && s[right]==' '){
            right--;
        }
        int len=0;
        for(int i=right;i>=left;i--){
            if(s[i]!=' ')len++;
            else break;
        }
        return len;
    }
};