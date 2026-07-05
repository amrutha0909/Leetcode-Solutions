class Solution {
public:
    bool isPalindrome(int x) {
        long long rev=0;
        long long original=x;
        while(x>0){
            rev=rev*10+x%10;
            x/=10;
        }
        return rev==original;
    }
};