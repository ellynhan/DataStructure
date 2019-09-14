#include <stdio.h>
#include <stdlib.h>

int tmp;
int arr[65537];
int K,N;
int S[65537];
int num;

int main(){

    FILE *If=fopen("parking.inp","r");
    FILE *Of=fopen("parking.out","w+");

    if (If==NULL){
    fprintf(stdout, "parking.inp ������ ���� ���߽��ϴ�.");
    exit(1);
    }

    fscanf(If,"%d\n", &K);
    fscanf(If,"%d\n", &N);

    while(!feof(If)){
        fscanf(If, "%d", &tmp);

        if(tmp > 0) {
            int i = 0;
            while(num <= K){
                if(arr[i] == 0){
                    arr[i] = tmp;
                    num++;
					break;
                }
                else
					i++;
           }
           if(num > K){
                K=2*K;
            }
            else{}
        }
        else{
            int j=0;
            while(1){
                if(arr[j] == -tmp){
                    arr[j]=0;
                    num--;
					break;
                }
                else
					j++;
           }
           if(num <= K/3){
                K = K/2;
                int j=0;
                int i=0;
                for(i=0; i<2*K; i++){
                    if(arr[i]!=0){
                        S[j]=arr[i];
                        arr[i]=0;
                        j++;
                    }
                }
                i=0;
                for(j=0; j<num; j++){
                    if(S[j]!=0){
                        arr[i]=S[j];
                        i++;
                    }
                }
            }

        }
    }
    int j;
    for(j=0; j<K; j++){
        if(arr[j]!=0){
            fprintf(Of, "%d %d\n", j+1, arr[j]);
        }
    }
        fclose(If);
        fclose(Of);
        return 0;
}