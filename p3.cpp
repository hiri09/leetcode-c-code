#include<bits/stdc++.h>
using namespace std;
class disjoint_set{
    public:
    vector<int>rank,parent,size;
    disjoint_set(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find_parent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find_parent(parent[node]);
    }
    void make_union(int u,int v){
        int ult_u=find_parent(u);
        int ult_v=find_parent(v);

        if(ult_u==ult_v){
            return;
        }

        if(rank[ult_u]>rank[ult_v]){
            parent[ult_v]=ult_u;
        }
        else if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }
    void make_size(int u,int v){
        int ult_u=find_parent(u);
        int ult_v=find_parent(v);

        if(ult_u==ult_v){
            return;
        }
        if(size[ult_u]>size[ult_v]){
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
        else{
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
    }
};

int main(){
    cout<<"hello brother"<<endl;
    return 0;
}

