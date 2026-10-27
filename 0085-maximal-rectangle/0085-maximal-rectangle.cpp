class Solution {
public:
    int largest(vector<int>& h){
        int n=h.size();
        vector<int>psi(n,-1);
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && h[st.top()]>=h[i]) st.pop();
            if(st.size() > 0)
                psi[i] = st.top();
            st.push(i);
        }
        vector<int>nsi(n,n);
        stack<int>gt;
        gt.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(gt.size()>0 && h[gt.top()]>=h[i]) gt.pop();
            if(gt.size() > 0)
            nsi[i] = gt.top();
            gt.push(i);
        }
        int mA=0;
        for(int i=0;i<n;i++){
            int he=h[i];
            int b=nsi[i]-psi[i]-1;
            int a=he*b;
            mA=max(a,mA);
        }
        return mA;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>h(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1') h[j]++;
                else h[j]=0;
            }
            ans=max(ans,largest(h));
        }
        return ans;
    }
};