class Solution {
public:
    long long sumAndMultiply(int n) {
        string s="";
        long long sum=0;
        while(n>0){
            sum+=n%10;
            if(n%10!=0)s+=n%10+'0';
            n/=10;
        }
        if(s.empty())return 0;
        reverse(s.begin(),s.end());
        long long num=stoi(s);
        return num*sum;
    }
};