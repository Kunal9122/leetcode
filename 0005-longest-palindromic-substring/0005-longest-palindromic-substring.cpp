class Solution {
public:
    void expand(string s,int l,int r,string &res){
        while(l>=0 && r<s.size()&& s[l]==s[r]){
            if(r-l+1>res.size()){
                res=s.substr(l,r-l+1);
            }
            l--;r++;
        }
    }
    string longestPalindrome(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            expand(s,i,i,res);
            expand(s,i,i+1,res);
        }
        return res;
    }
};