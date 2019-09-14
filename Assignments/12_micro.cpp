#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,sum;
bool compare(int a, int b){
    return a>=b;
}

void checkfunc(int** dbarr,int s, int g){
    if(s<m-1&&dbarr[s+1][g]==1){
        sum++;
        dbarr[s+1][g]=0;
        checkfunc(dbarr,s+1,g);
    }
    if(g<n-1&&dbarr[s][g+1]==1){
        sum++;
        dbarr[s][g+1]=0;
        checkfunc(dbarr,s,g+1);
    }
    if(g>0&&dbarr[s][g-1]==1){
        sum++;
        dbarr[s][g-1]=0;
        checkfunc(dbarr,s,g-1);
    }
    if(s>0&&dbarr[s-1][g]==1){
        sum++;
        dbarr[s-1][g]=0;
        checkfunc(dbarr,s-1,g);
    }
}

int main(){
    ifstream read("micro.inp");
    vector<int> virus;
    char input;
    read>>n>>m>>k;
    int** check=new int*[m];
    for(i=0; i<m; i++){
        check[i]=new int[n];
        for(j=0; j<n; j++){
            read>>input;
            if(input=='#')
                check[i][j]=1;
            else
                check[i][j]=0;
        }
    }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(check[i][j]==1){
                sum++;
                check[i][j]=0;
                checkfunc(check,i,j);
                if(sum>=k)
                    virus.push_back(sum);
                sum=0;
            }
        }
    }
    ofstream out("micro.out");
    if(virus.size()){
        sort(virus.begin(), virus.end(), compare );
        out<<virus.size()<<" "<<virus[0];
    }
	else
        out<<"0 0";
}
