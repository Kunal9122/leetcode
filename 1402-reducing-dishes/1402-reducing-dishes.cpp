class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
       int n=satisfaction.size();
       int arr[n];
       int ans=0;
       sort(satisfaction.begin(),satisfaction.end());
       arr[n-1]=satisfaction[n-1]; 
       int idx=-1;
       for(int i=n-2;i>=0;i--){
        arr[i]=arr[i+1]+satisfaction[i];
       }
       for(int i=0;i<n;i++){
        if(arr[i]>=0){
            idx=i;
            break;
        }
       }
       if(idx==-1) return 0;
       int x=1;
       for(int i=idx;i<n;i++){
        ans=ans+(satisfaction[i]*x);
        x++;
       }
       return ans;
    }
};