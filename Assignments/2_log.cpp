#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream readFile("syslog.txt");
    int logDay;
    readFile>>logDay;
    int** days=new int*[logDay];
    int** times=new int*[logDay];
    int temp[10000]={0,};
    
    for(int i=0; i<logDay; i++){
        days[i]=new int[2];//day,length
        readFile>>days[i][0];
        int x;
        readFile>>x;
        int j=0;
        while(x!=0){
            temp[j]=x;
            readFile>>x;
            j++;
        }
        days[i][1]=j;//length
        times[i]=new int[j];
        for(int k=0; k<j; k++){
            times[i][k]=temp[k];
            temp[k]=0;
        }
    }
    readFile.close();
    ifstream input("log.inp");
    ofstream outFile("log.out");
    int n;
    input >> n;
    int** sd_st_ed_et=new int*[n];
    for(int i=0; i<n; i++){
        int tmp;
        sd_st_ed_et[i]=new int[4];
        for(int j=0; j<4; j++){
            input>>tmp;
            sd_st_ed_et[i][j]=tmp;
        }
        int sum=0;

        for(int j=0; j<logDay; j++){
            if(sd_st_ed_et[i][0]<days[j][0]){
                if(days[j][0]<sd_st_ed_et[i][2]){
                    sum+=days[j][1];
                }
                else if(days[j][0]==sd_st_ed_et[i][2]){
                    if(sd_st_ed_et[i][3]>times[j][days[j][1]-1]){
                        sum+=days[j][1];
                    }
                    else{
                        for(int k=0; k<days[j][1]; k++){
                        if(sd_st_ed_et[i][3]<times[j][k]){
                            sum+=k;
                            break;
                        }
                        else if(sd_st_ed_et[i][3]==times[j][k]){
                            sum+=k+1;
                            break;
                            }
                        }
                    }
                }
            }
            else if(sd_st_ed_et[i][0]==days[j][0]){
                if(sd_st_ed_et[i][2]==days[j][0]){
                    for(int k=0; j<days[j][1];k++){
                        if(sd_st_ed_et[i][1]<=times[j][k]){
                            sum-=k;
                            break;
                        }
                    }
                    if(sd_st_ed_et[i][3]>times[j][days[j][1]-1]){
                        sum+=days[j][1];
                    }
                    else{
                        for(int k=0; j<days[j][1];k++){
                        if(sd_st_ed_et[i][3]<times[j][k]){
                            sum+=k;
                            break;
                            }
                        else if(sd_st_ed_et[i][3]==times[j][k]){
                            sum+=k+1;
                            break;
                            }
                        }
                    }
                }
                else if(sd_st_ed_et[i][2]>days[j][0]){
                    for(int k=0; k<days[j][1]; k++){
                        if(sd_st_ed_et[i][1]<=times[j][k]){
                            sum-=k;
                            sum+=days[j][1];
                            break;
                        }
                    }
                }
            }
        }
        if(i<n-1) outFile<<sum<<endl;
        if(i==n-1) outFile<<sum;
    }
}
