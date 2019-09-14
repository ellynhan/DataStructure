#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
int k1,k2,count=0;
vector<string> stackOfFunc,store;
ofstream outFile("function.out");
bool Deadlock(string f){
    for(int i=1; i<stackOfFunc.size()-1; i++){
        if(stackOfFunc[i]==f){
            outFile<<"DEADLOCK";
            return true;
        }
    }
    return false;
}
int function(vector<vector<string> >& v,int k){
    int i=1;
    while(v[k][i]!="$"){
        if(v[k][i]>="A"&&v[k][i]<="Z"){
            for(int j=1; j<v.size(); j++){
                if(v[j][0]==v[k][i]){
                    stackOfFunc.push_back(v[k][i]);
                    if(Deadlock(v[j][0]))return 1;
                    if(function(v,j))return 1;
                    break;
                }
            }
        }
        else{
            count++;
            if(count==k1){
                store[0]=v[k][0]+"-"+v[k][i];
            }
            if(count==k2){
                store[1]=v[k][0]+"-"+v[k][i];
            }
        }
        i++;
    }
    stackOfFunc.pop_back();
    return 0;
}

int main(){
    store.push_back("]");
    store.push_back("]");
    int n;
    ifstream readFile("function.inp");
    readFile>>n>>k1>>k2;
    vector<vector<string> > v(n,vector<string>(0));
    for(int i=0; i<n; i++){
        string tmp;
        readFile>>tmp;
        while(tmp!="$"){
            v[i].push_back(tmp);
            readFile>>tmp;
        }
        v[i].push_back("$");
    }
    int func=0,ele=1;
    stackOfFunc.push_back("M");
    while(stackOfFunc.size()!=0){
        if(v[func][ele]>="A"&&v[func][ele]<="Z"){
            int k=1;
            while(k<n&&v[func][ele]!=v[k][0]){k++;}
            stackOfFunc.push_back(v[k][0]);
            if(Deadlock(v[k][0]))return 0;
            if(function(v,k))return 0;
        }
        else if(v[func][ele]=="$"){
            stackOfFunc.pop_back();
        }
        else{
            count++;
            if(count==k1){
                store[0]=v[func][0]+"-"+v[func][ele];
            }
            if(count==k2){
                store[1]=v[func][0]+"-"+v[func][ele];
            }
        }
        ele++;
    }
    for(int i=0; i<2; i++){
        if(store[i]=="]"){outFile<<"NONE"<<endl;}
        else
            outFile<<store[i]<<endl;
    }
    return 0;
}
