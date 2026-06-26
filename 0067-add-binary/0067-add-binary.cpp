class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        int sum=0;
        while(i>=0 || j>=0 || carry){
            if(i>=0)sum+=a[i]-'0';
            if(j>=0)sum+=b[j]-'0';
            sum+=carry;
            carry=0;
            if(sum==1){
                ans+="1";
            }
            else if(sum==2){
                ans+="0";
                carry=1;
            }
            else if(sum==3){
                ans+="1";
                carry=1;
            }
            else{
                ans+="0";
            }
            sum=0;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};