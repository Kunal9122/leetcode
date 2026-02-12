class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string>s;
        int c=0;
        for(int i=0;i<words.size();i++){
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            if(s.find(rev)!=s.end()){
                c++;
            }
            s.insert(words[i]);
        }
        return c;
    }
};