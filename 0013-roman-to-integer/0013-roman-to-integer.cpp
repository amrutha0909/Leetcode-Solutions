class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>val;
        val['I']=1;
        val['V']=5;
        val['X']=10;
        val['L']=50;
        val['C']=100;
        val['D']=500;
        val['M']=1000;
        int n=s.size();
        int sum=val[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(val[s[i]]<val[s[i+1]]){
                sum-=val[s[i]];
            }
            else{
                sum+=val[s[i]];
            }
        }
        return sum;
    }
};