class Solution {
public:
    int fn(string s){
        vector<int> v(26,0);
        for(auto it : s){
            v[it-'a']++;
        }

        for(int i = 0;i<26;i++){
            if(v[i] != 0) return v[i];
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        int m = words.size();

        vector<int> arr1(n,0);
        vector<int> arr2(m,0);
        for(int i = 0;i<n;i++){
            arr1[i] = fn(queries[i]);
        }
        for(int i = 0;i<m;i++){
            arr2[i] = fn(words[i]);
        }

        sort(arr2.begin(),arr2.end());
        for(int i = 0;i<n;i++){
            int x = arr1[i];

            int s = 0;
            int e = m-1;
            int idx = -1;
            while(s <= e){
                int mid = (s+e)/2;

                if(arr2[mid] > x){
                    idx = mid;
                    e = mid - 1;
                }else{
                    s = mid + 1; 
                }
            }

            if(idx != -1) arr1[i] = m - idx;
            else arr1[i] = 0;
        }
        return arr1;
    }
};