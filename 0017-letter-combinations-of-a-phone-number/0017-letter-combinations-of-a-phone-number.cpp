class Solution {
public:
    void helper(map<int,string>mp,string digits,vector<string>& ans,string &s,int id){
        if(id>=digits.size()){
            ans.push_back(s);
            return;
        }
        int r=digits[id]-'0';
        string k=mp[r];
        for(int i=0;i<k.size();i++){
            s+=k[i];
            helper(mp,digits,ans,s,id+1);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
         if(digits.size() == 0) return {}; 
        map<int,string>mp;
        mp[2]="abc";    mp[6]="mno";
        mp[3]="def";    mp[7]="pqrs";
        mp[4]="ghi";    mp[9]="wxyz";
        mp[5]="jkl";    mp[8]="tuv";
        vector<string>ans;
        string s="";
        helper(mp,digits,ans,s,0);
        return ans;
    }
};