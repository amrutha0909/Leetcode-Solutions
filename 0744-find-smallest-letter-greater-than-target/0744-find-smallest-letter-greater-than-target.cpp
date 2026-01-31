class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int val=target-'a';
        for(char ch:letters){
            if(ch-'a'>val){
                return ch;
            }
        }
        return letters[0];
    }
};