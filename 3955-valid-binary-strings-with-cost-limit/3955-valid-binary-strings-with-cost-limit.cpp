class Solution {
private:
    void fn(int idx, string temp, vector<string>&ans, int n, int k){
        //base case
        if(idx==n){
            int cnt=0;
            for(int i=0; i<temp.size(); i++){
                if(temp[i]=='1') cnt+=i;
            }
            if(cnt <= k) ans.push_back(temp);
            return;
        }

        if(temp.size()==0){
            fn(idx+1,temp+'0',ans,n,k);
            fn(idx+1,temp+'1',ans,n,k);
            return;
        }
    
        if(temp.back()=='1'){
            fn(idx+1,temp+'0',ans,n,k);
        }else{
            fn(idx+1,temp+'0',ans,n,k);
            fn(idx+1,temp+'1',ans,n,k);
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        int idx=0;
        string temp="";
        fn(idx,temp,ans,n,k);
        return ans;
    }
};