class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>v(26,false);
        for(int i=0;i<sentence.size();i++){
            int c=sentence[i]-97;
            v[c]=true;
        }
        for(int i=0;i<26;i++){
            if(v[i]==false) return false;
        }
        return true;
    }
};