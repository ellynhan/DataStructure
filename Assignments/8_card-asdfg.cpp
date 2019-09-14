#include <bits/stdc++.h>

using namespace std;

void cut(list<int>& l,int beg,int last)
{
    list<int>::iterator it1=l.begin(),it2=l.begin();
    advance(it1,beg-1);
    advance(it2,last);
    l.splice(it1, l, it2, l.end() ) ;
}
void shuffle(list<int>& l)
{
    list<int>::iterator it1 = l.begin(), it2 = l.begin();
    int n = (l.size()+1)/2;
    advance(it2,n);
    while(n!=1) {
        ++it1;
        l.splice(it1,l,it2);
        advance(it2,n--);
    }
}
int main(void){
    ifstream ifs("card.inp");
    ofstream ofs("card.out");

    int N, K;
    int i,j;
    string work;

    ifs >> N >> K;
    list<int> card(N);
    int n = 0;
    list<int>::iterator it;
    for(it=card.begin();it!=card.end();++it) // list 초기화
        *it = ++n;
    for(n=0;n<K;++n) {
        ifs >> work;
        if(work == "Cut") {
            ifs >> i >> j;
            cut(card,i,j);
        }
        else
            shuffle(card);
    }
    it = card.begin();
    for(int i=1;i<=N;++i) {
        if(i==1 || i==N/2 || i==N)
            ofs << *it << ' ';
        ++it;
    }
    ifs.close();
    ofs.close();
	return 0;
}
