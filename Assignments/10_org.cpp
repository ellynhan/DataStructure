#include <bits/stdc++.h>
using namespace std;
struct node{
    string name;
    node* bptr;
    int minions=0;
    int depth=0;
};
int getdepth(node* nodes){
    if(nodes->bptr==nullptr)
        return 0;
    else
        return 1;
}
bool sortrule(node n1, node n2){
    if(n1.minions>n2.minions)
        return true;
    else if(n1.minions==n2.minions)
        if(n1.depth<n2.depth)
            return true;
        else if(n1.depth==n2.depth&&n1.name<n2.name)
            return true;
    return false;
}
int main(void){
    ifstream read("org.inp");
    int n,i,j,k,c=0;
    string b,m;
    read>> n;
    vector<node> nodes(n);
    for(i=0; i<n-1; i++){
        read>>m>>b;
        for(j=0; j<c&&nodes[j].name!=m; j++){}
        if(j==c){
            nodes[c++].name=m;
            j=c-1;
        }
        for(k=0; k<c-1&&nodes[k].name!=b; k++){}
        if(k<c-1){
            nodes[j].bptr=&nodes[k];
        }
        else{
            nodes[c++].name=b;
            nodes[j].bptr=&nodes[c-1];
        }
    }
    for(i=0; i<n; i++){
        node* tmp=&nodes[i];
        while(getdepth(tmp)){
            nodes[i].depth++;
            tmp=tmp->bptr;
            tmp->minions++;
        }
    }
    sort(nodes.begin(),nodes.end(),sortrule);
    ofstream out("org.out");
    for(i=0; i<n; i++){
        out<<nodes[i].name<<" ";
    }
}
