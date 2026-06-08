class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        if(st.find("0000")!=st.end()) return -1;
        queue<string>q;
        q.push("0000");
        unordered_set<string>v;
        v.insert("0000");
        int m=0;
        while(!q.empty()){
        int size=q.size();
        while(size--){
            string r=q.front();
            q.pop();
            if(r==target) return m;
            for(int i=0;i<4;i++){
                string up=r;
                string down=r;
                if(up[i]=='9'){
                    up[i]='0';
                }
                else up[i]=up[i]+1;
                if(down[i]=='0'){
                    down[i]='9';
                }
                else down[i]=down[i]-1;
                if(st.find(up)==st.end()&&v.find(up)==v.end()){
                    q.push(up);
                    v.insert(up);
                }
                if(st.find(down)==st.end()&&v.find(down)==v.end()){
                    q.push(down);
                    v.insert(down);
                }
            }
        }
        m++;
        }
        return -1;
    }
};