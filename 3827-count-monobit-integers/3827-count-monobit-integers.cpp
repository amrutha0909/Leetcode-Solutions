class Solution {
public:
    bool isMono(int n){
        int bin=0;
        vector<int>binary;
        while(n>0){
            int rem=n%2;
            binary.push_back(rem);
            n/=2;
        }
        reverse(binary.begin(),binary.end());
        int freqOne=0;
        int freqZero=0;
        for(int i=0;i<binary.size();i++){
            if(binary[i]==0)freqZero++;
            else freqOne++;
        }
        if(freqZero==binary.size()||freqOne==binary.size())return true;
        return false;
        
    }
    int countMonobit(int n) {
        int count=1;
        for(int i=1;i<=n;i++){
            if(isMono(i))count++;
        }
        return count;
    }
};