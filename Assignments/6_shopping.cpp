#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
int main()
{
    int n,k;
    ifstream readFile("shopping.inp");
    readFile>>n>>k;
    deque<int*>* q=new deque<int*>[k];
    int** info = new int*[n];
    for(int i=0; i<n; i++){info[i]=new int[2];}
    for(int i=0; i<n&&i<k; i++){
        readFile>>info[i][0]>>info[i][1];
        q[i].push_back(info[i]);
    }
    if(n>k){
        for(int i=k; i<n; i++){
        int inmin=0;
        readFile>>info[i][0]>>info[i][1];
        for(int j=1; j<k; j++){
            if(q[inmin].back()[1]>q[j].back()[1]) inmin=j;
        }
        info[i][1]+=q[inmin].back()[1];
        q[inmin].push_back(info[i]);
        }
    }
    ofstream outFile("shopping.out");
    while(n--){
        int outMin=k-1;
        while(q[outMin].empty()){outMin--;}
        for(int i=k-1; i>=0; i--){
            if(q[i].empty())continue;
            if(q[outMin].front()[1]>q[i].front()[1]) outMin=i;
        }
        outFile<<q[outMin].front()[0]<<endl;
        q[outMin].pop_front();
    }
}
