#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Info{
    int user,st,et;
};

bool func(Info a, Info b){
    if(a.st<b.st){
        return true;
    }
    else{
        return false;
    }
}

int main(void){
    ifstream readFile("log.inp");
    ofstream outFile("log.out");
    int n,k,u,s,e,q;
    readFile>>n>>k;
    list<Info> li;
    vector<int> answer;
    struct Info* info=new Info[n];
    for(int i=0; i<n; i++){
        readFile>>u>>s>>e;
        info[i].user=u;
        info[i].st=s;
        info[i].et=e;
        li.push_back(info[i]);
    }
    li.sort(func);
    list<Info>::iterator it;
    for(int i=0; i<k; i++){
        readFile>>q;
        for(it=li.begin(); it!=li.end()&&it->st<=q; it++){
            if(it->et>=q){
                answer.push_back(it->user);
            }
        }
        if(answer.empty()){
            answer.push_back(0);
        }
        else{
            sort(answer.begin(),answer.end());
        }
        for(int i=0; i<answer.size(); i++){
            outFile<<answer[i]<<" ";
        }
        answer.clear();
        outFile<<endl;
    }
}
