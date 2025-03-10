class Solution {
    public:
        bool isPalindrome(int x) {
            if(x<0){
                return false;
            }
            int rem;
            long int rev=0;
            int num=x;
            while(num>0){
                rem=num%10;
                rev=rev*10+rem;
                num/=10;
            }
            return rev==x;
        }
    };