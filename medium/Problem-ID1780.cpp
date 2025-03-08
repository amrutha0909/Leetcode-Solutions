class Solution {
    public:
        bool checkPowersOfThree(int n) {
            int rem=0;
            long long int tern=0;
            long long int num=n;
            while(n>0){
                rem=n%3;
                tern=tern*10+rem;
                n=n/3;
            }
    
            while(tern>0){
                if(tern%10==2){
                   return false;
                }
                tern/=10;
            }
            return true;
        }
    };