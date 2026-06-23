class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            if(haystack.substr(i).starts_with(needle))return i;
        }
        return -1;
    }
};