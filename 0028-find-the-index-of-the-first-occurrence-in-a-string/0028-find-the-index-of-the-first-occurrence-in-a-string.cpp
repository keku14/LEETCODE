class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int len = needle.size();

        for(int i =0 ;i<n;i++){
            if(haystack[i] == needle[0]){
                string k = haystack.substr(i,len);
                if(k == needle){
                    return i;
                }
            }
        }
        return -1;
    }
};