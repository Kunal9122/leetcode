class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()) return s;
        string s1="";
        vector<string>ans(numRows);
        int c=0;
        int dir=1;
        for(char ch: s ){
            ans[c]+=ch;
            if(dir==1&&c==numRows-1){
                dir=0;
            }
            if(c==0 && dir==0) dir=1;
            if(dir==0){
                c--;
            }
            else{
                c++;
            }
        }
        for(int i=0;i<ans.size();i++){
            s1+=ans[i];
        }
        return s1;
    }
};