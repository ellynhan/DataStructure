#include <bits/stdc++.h>
using namespace std;

class org;
vector<org*> order;

class org {
	string person;
	string boss;
	vector<org*> emp; // 부하 직원
	int empNum = 0; // 부하 직원 수
	int depth = 0;
public:
	org(string p, string b) {
		person = p;
		boss = b;
		order.push_back(this);
	}
	void inDepth(int d) {
		depth = d + 1;
	}
	int getEmpNum() {
        return empNum;
	}
	int getDepth() {
        return depth;
	}
	string getPerson() {
        return person;
	}
	void setTree(map<string, string>& orgMap) { // recursive
		org* tm;
		for (auto it = orgMap.begin(); it != orgMap.end(); ++it) {
			if (it->second == person) {
				tm = new org(it->first, it->second);
				tm->inDepth(depth);
				tm->setTree(orgMap);
                empNum += tm->getEmpNum();
				emp.push_back(tm);
			}
		}
		empNum += emp.size();
	}
};

bool compare(org* p1, org* p2) {
    if(p1->getEmpNum() == p2->getEmpNum()) {
        if(p1->getDepth() == p2->getDepth()) {
            return p1->getPerson() < p2->getPerson();
        }
        else return p1->getDepth() < p2->getDepth();
    }
    else return p1->getEmpNum() > p2->getEmpNum();
}

int main()
{
	string b, p;
	int N;
	org* tm;
	map<string, string> orgIn; // key: person, value: boss

	ifstream inp("org.inp");
	if (inp.is_open()) {
		inp >> N;
		for (int i = 1; i<N; ++i) {
			inp >> p >> b;
			orgIn[p] = b;
		}
	}
	inp.close();

	for (auto it = orgIn.begin(); it != orgIn.end(); ++it) {
		if (orgIn.count(it->second) == 0) {
			tm = new org(it->second, "");
			tm->setTree(orgIn);
			break;
		}
	}

	sort(order.begin(), order.end(), compare);
	ofstream out("org.out");
	if(out.is_open()) {
        for(auto it = order.begin(); it < order.end(); ++it)
            out << (*it)->getPerson() << " ";
	}
    out.close();

	return 0;
}
