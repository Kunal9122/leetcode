class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>s;
        int n=fruits.size();
        if(n<=2) return n;
        int i=0,j=0,len=0;
        while(j<n){
            s[fruits[j]]++;
            if(s.size()<=2){
                len=max(len,j-i+1);
            }
            while(i<j && s.size()>2){
                s[fruits[i]]--;
                if(s[fruits[i]]==0) s.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return len;
    }
};