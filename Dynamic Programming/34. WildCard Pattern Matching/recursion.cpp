bool f(int i,int j,string& pattern,string& text){
    if(i<0 and j<0) return true;
    if(i>=0 and j<0){
        for(int ii=0;ii<=i;ii++){
            if(pattern[ii]!='*') return false;
        }
        return true;
    }
    if(i<0 and j>=0) return false;
    if(pattern[i]==text[j] || pattern[i]=='?') return f(i-1,j-1,pattern,text);
    if(pattern[i]=='*'){
        return f(i-1,j,pattern,text) | f(i,j-1,pattern,text);
    }
    return false;
}
bool wildcardMatching(string pattern, string text){
   // Write your code here.
    int n=pattern.size(), m=text.size();
    return f(n-1,m-1,pattern,text);
}
