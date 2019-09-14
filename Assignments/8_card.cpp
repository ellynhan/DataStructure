//cut은 리스트로 구현 (splice 이용)
//shuffle:  deck을 두개로 나누어서 번갈아서 촤라라라라라락 해서 하나로 합치기
#include <iostream>
#include <list>
#include <queue>
#include <fstream>
using namespace std;
int main(void){
    list<int> li;
    list<int>::iterator iter,iter2;
    queue<int> deckA, deckB;
    int n,k,i;
    string work;
    ifstream input("card.inp");
    input>>n>>k;
    for(i=0; i<n; i++)
        li.push_back(i+1);//카드 저장
    while(k--){//k번 작업
        input>>work;//command 받음
        if(work=="Shuffle"){
            //우선 deckA와 deckB에 나누어 놓기
            for(i=0; i<n; i++){
                if(i<n/2||(n%2!=0&&i==n/2)){
                    deckA.push(li.front());
                    li.pop_front();
                }
                else{
                    deckB.push(li.front());
                    li.pop_front();
                }
            }
            //deckA deckB 번갈아가며 섞기.
            for(i=0; i<n; i++){
                if(i%2==0){
                    li.push_back(deckA.front());
                    deckA.pop();
                }
                else{
                    li.push_back(deckB.front());
                    deckB.pop();
                }
            }
        }
        else if(work=="Cut"){
            int b,e;
            input>>b>>e;//begin,end
            for(iter=li.begin(),iter2=li.begin(),i=0;i<e; i++){
                if(i<b-1)
                    iter++;
                iter2++;
            }
            li.splice(li.end(),li,iter,iter2);
        }
        else{
            cout<<"error";
        }
    }
    ofstream output("card.out");
    for(iter=li.begin(),i=0; i<n/2-1; iter++,i++){}
    output<<li.front()<<" "<<*iter<<" "<<li.back();

    /*for(iter=li.begin(); iter!=li.end(); iter++){
        output<<*iter<<" ";
    }*/
}
