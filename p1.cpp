#include<bits/stdc++.h>
using namespace std;
/*int solve(vector<int>&v,int n,int k){
    int sum=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int i=0;
    int count=0;
    while(i<n){
        sum+=v[i];
        if(mp.find(sum-k)!=mp.end()){
           count+=mp[sum-k];
        }
        mp[sum]++;
        i++;
    }
    return count;
}*/
int solve(vector<int>&v,int n,int k){
    int sum=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int i=0;
    int count=0;
    while(i<n){
        sum+=v[i];
        int rem=sum%k;
        if(rem<0){
            rem+=k;
        }

        if(mp.find(rem)!=mp.end()){
           count+=mp[rem];
        }
        mp[rem]++;
        i++;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k;
    cin>>k;
    cout<<solve(v,n,k)<<endl;
    return 0;
}