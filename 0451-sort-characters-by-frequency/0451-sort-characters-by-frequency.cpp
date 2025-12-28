class Solution {
public:
    typedef pair<int,char>pi;
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        priority_queue<pi>pq;
        for(auto c : mp){
            pi p={c.second,c.first};
            pq.push(p);
        }
        string ans="";
        while(pq.size()){
            int c=pq.top().first;
            char ch=pq.top().second;
            for(int i=0;i<c;i++){
                ans+=ch;
            }
            pq.pop();
        }
        return ans;
    }
};