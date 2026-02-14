class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>ans;
        for(int i=100;i<=999;i++){
            if(i%2!=0) continue;
            int x=i;
            bool flag=true;
             unordered_map<int,int>temp=mp;
            while(x){
                int a=x%10;
                if(temp[a]>0){
                    temp[a]--;
                }
                else{
                    flag=false;
                    break;
                }
                x=x/10;
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};