class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            vector<int>rHash(26,0);
            vector<int>mHash(26,0);
            for(int i=0;i<ransomNote.size();i++){
                int z=ransomNote[i]-'a';
                rHash[z]+=1;
            }
            for(int i=0;i<magazine.size();i++){
                int z=magazine[i]-'a';
                mHash[z]+=1;
            }
    
    
            for(int i=0;i<rHash.size();i++){
                if(rHash[i]>mHash[i])
                return false;
            }
            return true;
        }
    };