class Solution {
public:
    bool checkOnesSegment(string s) {
        int oneCount=0;
        if(s.size()==1){
            if(s[0]=='1')return true;
        }
        int zeroCount=0;
        int contig=0;
        if(s.size()==2){
            if(s[0]=='1'||s[1]=='1')return true;
        }
        for(char c:s){
            if(c=='1'){
                oneCount++;
            }
            else if(c=='0'){
                if(oneCount>=1)contig++;
                oneCount=0;
                zeroCount++;
            }
        }
        if(oneCount>=1)contig++;
        if(contig==1)return true;
        if(zeroCount==s.size()-1)return true;
        return false;
    }
};