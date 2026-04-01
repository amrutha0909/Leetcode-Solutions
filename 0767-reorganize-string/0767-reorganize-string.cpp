class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mpp;
        for(char c:s){
            mpp[c]++;
        }
        int maxFreq=0;
        int maxChar='a';
        for(int i=0;i<s.size();i++){
            int freq=mpp[s[i]];
            if(freq>maxFreq){
                maxFreq=freq;
                maxChar=s[i];
            }
        }
        if(maxFreq>(s.size()+1)/2)return "";
        vector<char>result(s.size());
        int index=0;
        while(mpp[maxChar]>0&&index<s.size()){
            result[index]=maxChar;
            index+=2;
            mpp[maxChar]--;
        }
        for(char c:s){
            while(mpp[c]>0){
                if(index>=result.size()){
                    index=1;
                }
                result[index]=c;
                index+=2;
                mpp[c]--;
            }
        }
        string ans="";
        for(char c:result){
            ans+=c;
        }
        return ans;
    }
};