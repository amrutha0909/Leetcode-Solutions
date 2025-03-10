class Solution {
    public:
        void reverseString(vector<char>& s) {
            int size=s.size();
            vector<char>t(size);
            for(int i=0;i<size;i++){
                t[i]=s[size-i-1];
            }
            for(int i=0;i<size;i++){
                s[i]=t[i];
            }
        }
    };