class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
      int n=cost[0];
      for(int i=0;i<cost.size();i++){
        if(cost[i]<n) n=cost[i];
        cost[i]=n;
      }
      return cost;
    }
};