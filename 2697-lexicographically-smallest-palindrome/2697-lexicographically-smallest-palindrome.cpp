class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        int start=0;
        int end=s.size()-1;
        while(start <= end){
            if(s[start] < s[end]){
                s[end]=s[start];
            }else if(s[end] < s[start]){
                s[start]=s[end];
            }
            end--;
            start++;
        }
        return s;
    }
};