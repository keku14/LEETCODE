class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto it : wordList){
            st.insert(it);
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        if(!st.count(endWord)) return 0;
        while(!q.empty()){
            string curr = q.front().first;
            int step = q.front().second;
            q.pop();

            if(curr == endWord) return step;
            for(int i = 0;i<curr.length();i++){
                char orig = curr[i];
                for(char c = 'a';c<='z';c++){
                    curr[i] = c;
                    if(st.count(curr)){
                        q.push({curr,step+1});
                        st.erase(curr);
                    }
                }
                curr[i] = orig;
            }
        }
        return 0;
    }
};