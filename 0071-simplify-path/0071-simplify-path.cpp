class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string str="";
        for(int i=0;i<=path.size();i++){
            if(i==path.size()||path[i]=='/'){
                if(str == "" || str == ".") {
                    // do nothing
                }
               else if(str==".."){
                if(!st.empty()) st.pop();
               }
                else st.push(str);
                str="";
            }else{
                str+=path[i];
            }
        }
        string ans="";
        while(st.size()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans=="") return "/";
        return ans;
    }
};