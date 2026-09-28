class Solution {
public:
    int maxDepth(string s) {
        int maximum=0;
        int k=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
               k++;
               if(k>maximum){
                maximum=k;
               }
            }
            if(s[i]==')'){
                k--;
            }
        }
        return maximum;
    }
};