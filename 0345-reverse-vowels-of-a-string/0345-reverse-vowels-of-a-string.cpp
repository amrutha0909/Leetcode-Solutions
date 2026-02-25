class Solution {
public:
    string reverseVowels(string s) {
        int left=0;
        int right=s.size()-1;
        unordered_set<char>st={'a','A','e','E','i','I','o','O','u','U'};
        while(left<right){
            while(left<right && st.count(s[left])==0)left++;
            while(left<right && st.count(s[right])==0)right--;
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};