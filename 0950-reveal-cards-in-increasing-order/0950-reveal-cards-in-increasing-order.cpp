class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>q;
        int n=deck.size();
        vector<int>ans(n);
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int i=0;
        while(!q.empty()){
            int idx=q.front();
            ans[idx]=deck[i];
            i++;
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};