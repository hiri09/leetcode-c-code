#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s){
    if(s[0]=='0'){
        return false;
    }
    int n=stoi(s);
    if(n>255){
        return false;
    }
    cout<<s<<endl;
    return true;
}
void fun(string s,vector<string> &ans,string work,int idx,int p){
    if(idx==s.length()){
        if(p==4){
            ans.push_back(work.substr(0,work.length()-1));
        }
        return;
    }
    fun(s,ans,work+s[idx]+'.',idx+1,p+1);
    if(idx+2<=s.length() && isvalid(s.substr(idx,2))==true){
        fun(s,ans,work+s.substr(idx,2)+'.',idx+2,p+1);
    }
    if(idx+3<=s.length() && isvalid(s.substr(idx,3))==true){
        fun(s,ans,work+s.substr(idx,3)+'.',idx+3,p+1);
    }
}
vector<string> solve(string s){
   vector<string>ans;
   if(s.length()>12){
     return ans;
   }
   for(auto it:s){
    if(it>='0' && it<='9'){
        continue;
    }
     return ans;
   }
   fun(s,ans,"",0,0);
   return ans;
}
int main(){
    string s;
    cin>>s;
    vector<string>ans=solve(s);
    for(auto it:ans){
        cout<<it<<" "<<endl;
    }
    return 0;
}