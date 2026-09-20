class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        int r=0,c=0;
        while(1){
        for(int i=0;i<matrix.size();i++){
            pq.push(matrix[i][r]);
            if(pq.size()>k) pq.pop();
        }
        r++;
        if(r>=matrix.size()) break;
        }
        return pq.top();
    }
};