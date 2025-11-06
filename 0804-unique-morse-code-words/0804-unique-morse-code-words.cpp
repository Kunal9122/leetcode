class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>str={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            string ans2="";
            for(int j=0;j<words[i].size();j++){
                int c=words[i][j]-97;
                ans2+=str[c];
            }
            ans.push_back(ans2);
        }
        int co=0;
        sort(ans.begin(),ans.end());
        for(int i=1;i<ans.size();i++){
            if(ans[i-1]!=ans[i]) co++;
        }
        return co+1;
    }
};