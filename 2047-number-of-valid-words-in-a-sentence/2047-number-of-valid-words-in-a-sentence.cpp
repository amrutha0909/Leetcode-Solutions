class Solution {
public:
    bool isValid(string word){
        int hyphen=0;
        int punctuation=0;
        for(int i=0;i<word.size();i++){
            if (isdigit(word[i])) return false;
            if(word[i]=='-'){
                hyphen++;
                if(hyphen>1)return false;
                if(i==0 || i==word.size()-1)return false;
                if(!islower(word[i-1])||!islower(word[i+1]))return false;
            }
            if(word[i]=='!'||word[i]==','||word[i]=='.'){
                punctuation++;
                if(punctuation>1)return false;
                if(i!=word.size()-1)return false;
            }
        }
        return true;
    }
    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string word;
        int count=0;
        while(ss>>word){
            if(isValid(word))count++;
        }
        return count;
    }
};