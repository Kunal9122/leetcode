class Solution {
public:
    int myAtoi(string s) {
    string str="";
    int i=0;
    while(i<s.size() && s[i]==' '){
        i++;
    }
    if(i < s.size() && (s[i]=='-' || s[i]=='+')){
        str+=s[i];
        i++;
    }
    for(int j=i;j<s.size();j++){
        if(s[j]<48 || s[j]>57){
            break;
        }
        str+=s[j];
    }
    if(str == "" || str == "+" || str == "-") return 0;
    int k=0;
    int l=1;
    if(k<str.size()&&str[k]=='-'){
        l=-1;
        k++;
    }
    if(k<str.size()&&str[k]=='+'){
        l=1;k++;
    }
    long long m=0;
    for(int j=k;j<str.size();j++){
        int a=str[j]-48;
        m=m*10+a;
        if( l*m > INT_MAX) return INT_MAX;
        if(l * m < INT_MIN) return INT_MIN;
    }
    return m*l;
    }
};