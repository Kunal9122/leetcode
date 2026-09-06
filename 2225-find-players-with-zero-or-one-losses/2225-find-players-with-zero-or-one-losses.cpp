class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mp;
        set<int>s;
        for(int i=0;i<matches.size();i++){
            int l=matches[i][1];
            mp[l]++;
        }
        vector<int>win;
        for(int i=0;i<matches.size();i++){
            if(mp.find(matches[i][0])==mp.end()){
                if(s.find(matches[i][0])==s.end()){
                    win.push_back(matches[i][0]);
                    s.insert(matches[i][0]);
                }
            }
        }
        vector<int>loose;
        while(mp.size()>0){
            auto x=mp.begin();
            int s=x->second;
            int f=x->first;
            if(s==1) loose.push_back(f);
            mp.erase(x);
        }
        sort(win.begin(),win.end());
        sort(loose.begin(),loose.end());
        return {win,loose};
    }
};