#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int main(){
    ifstream in("rank.inp");
    int n,i=0;
    in>>n;
    int** log=new int*[n],*r=new int[n];
    while(i<n){
        int j=1,t;
        in>>t;
        log[i]=new int[31],r[i]=i;
        while(t!=-1){
            log[i][j++]=t;
            in>>t;}
        log[i][0]=j-1,sort(log[i]+1,log[i]+log[i][0]+1);
        for(int k=0; k<i; k++){
            if(log[i][0]>log[r[k]][0]){ for(int l=i; l>k; l--){r[l]=r[l-1];}
                r[k]=i;
                break;
            }else if(log[i][0]==log[r[k]][0]){
                for(int x=1; x<=log[i][0]; x++){
                    if(log[i][x]>log[r[k]][x]){ for(int l=i; l>k; l--){r[l]=r[l-1];}
                        r[k]=i;
                        k=i,x=log[i][0]+1;
                    }
                    if(log[i][x]<log[r[k]][x]) break;
                }
            }
        }
        i++;
    }
    in.close();
    ofstream ot("rank.out");
    for(int i=0; i<n; i++)ot<<r[i]+1<<endl;
    ot.close();
}
