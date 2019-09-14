#include <bits/stdc++.h>
using namespace std;
struct Node{
    int user;
    long long st;
    long long et;
};
bool sortNode(Node a,Node b){
    return a.user<b.user;
}
int main(){
    int N,K;
    int u;
    long long s,e;
    ifstream in("log.inp");
    ofstream out("log.out");
    list<Node> LogList;
    list<Node>::iterator it;
    in>>N>>K;
    for(int i=0;i<N;i++){
        in>>u>>s>>e;
        Node NewNode;
        NewNode.user=u;
        NewNode.st=s;
        NewNode.et=e;
        LogList.push_back(NewNode);
    }
    LogList.sort(sortNode);
    for(int i=0;i<K;i++){
        int flag=0;
        in>>s;
        for (it=LogList.begin();it!=LogList.end();*it++){
            if((*it).st<=s &&(*it).et>=s){
                out<<(*it).user<<' ';
                flag=1;
            }
        }
        if(flag==0)
            out<<0;
        out<<endl;
    }
}