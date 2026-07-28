class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int> v(26,0);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
        }
        string res(n,'*');
        int l=0;
        int r=n-1;
        int mid=n/2;
        for(int i=0; i<26; i++){
            if(v[i]%2 !=0){
                res[mid]=i+'a';
                v[i]--;
            }
            while(v[i]%2 == 0 && v[i]>0){
                res[l]=i+'a';
                res[r]=i+'a';
                l++;
                r--;
                v[i]-=2;
            }
        }
        return res;
    }
};
