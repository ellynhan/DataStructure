#include <bits/stdc++.h>
using namespace std;

void Search (int** graph,int** check,int n,int x,int y, int depth){
    for(int i=0; i<n; i++){
        if(graph[y][i]==1&&x!=i){
            if(check[x][i]==0||check[x][i]>depth+1){
                check[x][i]=check[i][x]=depth+1;
                Search(graph,check,n,x,i,depth+1);      //Search by recursive func
            }
        }
    }
}

int main(){
    ifstream read("meeting.inp");
    vector<char> v; // name of each vertex
    int n,i,j,x=0,y=0,min=0;
    char tmp;
    read>>n;
    for(i=0; i<3; i++){ //friends first.
        read>>tmp;
        v.push_back(tmp);
    }
    int** graph=new int*[n];
    int** check=new int*[n]; //visit check
    for(i=0; i<n; i++){
        graph[i]=new int[n];
        check[i]=new int[n];
        for(j=0; j<n; j++){graph[i][j]=check[i][j]=0;} // initialization
    }
    for(i=0; i<n; i++){
        read>>tmp;
        for(x=0; x<v.size()&&v[x]!=tmp; x++){}
        if(x==v.size())v.push_back(tmp);       // save vertex without duplication
        read>>tmp;
        while(tmp!='$'){
            for(y=0; y<v.size()&&v[y]!=tmp; y++){}
            if(y==v.size())v.push_back(tmp);
            graph[x][y]=graph[y][x]=1;
            read>>tmp;
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(graph[i][j]){
                check[i][j]=check[j][i]=1;
                Search(graph,check,n,i,j,1); //check start
            }
        }
    }
    ofstream out("meeting.out");
    for(i=0; i<n; i++){
        for(j=0; j<3; j++){
            if(i!=j&&check[i][j]==0) // not reached case
            check[i][j]=n;           // prevent errors
        }
        sort(&check[i][0],&check[i][3]);
        if(check[min][2]>check[i][2]){min=i;}
        else if(check[min][2]==check[i][2]&&v[min]>v[i]){min=i;}
    }
    if(check[min][2]!=0)
        check[min][2]=check[min][2]*3-2; //vertex - edge - vertex - edge ..
    out<<v[min]<<endl<<check[min][2];
}
