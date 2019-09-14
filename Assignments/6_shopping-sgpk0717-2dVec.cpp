#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
size_t counter(const vector< vector<string> >& shop)
{
	size_t max=0;
	for(size_t i=0;i<shop.size();++i)
		if(shop[i].size() < shop[max].size())
			max = i;
	return max;
}
int main(void)
{
	size_t N, k, sz, num, max=0;
	string temp;	
	ifstream ifs1("shopping.inp");
	ifs1 >> N >> k;
	vector< vector<string> > shop(k);
	for(int i=0;i<N;++i){
		num = counter(shop);
		ifs1>>temp>>sz;
		for(int j=0;j<sz;++j)
			shop[num].push_back(temp);
	}
	ifs1.close();
	for(size_t i=0;i<shop.size();++i) 
		if(shop[i].size() > max)
			max = shop[i].size();
	ofstream ofs1("shopping.out");
	int j=shop.size()-1;
	for(size_t i=0;i<max;++i)
		for(j=shop.size()-1;j>=0;--j)
			if(i<shop[j].size()) 
				if(i+1==shop[j].size() || shop[j][i]!=shop[j][i+1])
					ofs1 << shop[j][i] << endl;		
	ofs1.close();
	return 0;	
}