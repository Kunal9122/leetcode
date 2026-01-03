class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k>0){
            int x=pq.top();
            int y=floor(x/2);
            x=x-y;
            pq.pop();
            pq.push(x);
            k--;
        }
        int total=0;
        while(pq.size()){
            total+=pq.top();
            pq.pop();
        }
        return total;
    }
};