class Solution {
public:
    string toGoatLatin(string sentence) {
        string result="";
        stringstream ss(sentence);
        vector<string>words;
        string token="";
        while(getline(ss,token,' ')){
            words.push_back(token);
        }
        for(int i=0;i<words.size();i++){
            string word=words[i];
            char c=word[0];
            if(c=='a'||c=='A' || c=='e'|| c=='E' || c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U'){
                word.append("ma");
                for(int j=0;j<i+1;j++){
                    word.append("a");
                }
                result.append(word);
                result.append(" ");
            }
            else{
                char first=word[0];
                reverse(word.begin(),word.end());
                word.pop_back();
                reverse(word.begin(),word.end());
                string f="";
                f+=first;
                word.append(f);
                word.append("ma");
                for(int j=0;j<i+1;j++){
                    word.append("a");
                }
                result.append(word);
                result.append(" ");
            }
        }
        result.pop_back();
        return result;
    }
};