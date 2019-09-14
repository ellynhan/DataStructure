#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	queue<int> rumorList; //save order and lastly print them.
	ifstream inp("rumor.inp");
	ofstream out("rumor.out");
	int pplNum, stNum, dayNum;
	inp >> pplNum >> stNum >> dayNum;
	vector<vector<int> > ppl(pplNum, vector<int>(0));
	int* check = new int[pplNum];
	for (int i = 0; i<pplNum; i++) {
		int centor, friends;
		inp >> centor >> friends;
		while (friends) {
			ppl[centor - 1].push_back(friends);
			inp >> friends;
		}
		sort(ppl[centor - 1].begin(), ppl[centor - 1].end());
		check[i] = 0;
	}
	int day = 1;
	vector<int> speaker;
	queue<int> listener,listener2;
	int nextspeaker;
	while (day <= dayNum) {
		if (day == 1) {//�ҹ��� ����
			rumorList.push(stNum);
			check[stNum - 1] = 1;
			speaker = ppl[stNum - 1]; //startNum�� �ִ� ���� �ҹ��� �ٿ����� ����
			if (speaker.size() != 0) {//�갡 ģ���� �������
				for (int i = 0; i < speaker.size(); i++) {//�ҹ��� �ٿ����� �ڱ� ģ�������� �� �ҹ�����
					check[speaker[i] - 1] = 1;
					rumorList.push(speaker[i]);
					listener.push(speaker[i]); //�ҹ��� �ٿ����� ģ������ �ҹ��� ��Ʈ�� �غ� ��
				}
			}
			/*else {//�갡 ģ���� ���� ��� �׳� ����ð� ���� �پ��°Źۿ� ����
				out << rumorList.front();
				//return 0;
			}*/
			day++;//�׷��ٺ��� �Ϸ簡 ����
		}
		else {
			if (day % 2 == 0) {
				while (!listener.empty()) {
					nextspeaker = listener.front();
					speaker = ppl[nextspeaker - 1];//�ҹ����� �������
					for (int i = 0; i < speaker.size(); i++) {
						if (!check[speaker[i] - 1]) {
							check[speaker[i] - 1] = 1;
							rumorList.push(speaker[i]);
							listener2.push(speaker[i]);
						}
					}
					listener.pop();
				}
				day++;
			}
			else {
				while (!listener2.empty()) {
					nextspeaker = listener2.front();
					speaker = ppl[nextspeaker - 1];//�ҹ����� �������
					for (int i = 0; i < speaker.size(); i++) {
						if (!check[speaker[i] - 1]) {
							check[speaker[i] - 1] = 1;
							rumorList.push(speaker[i]);
							listener.push(speaker[i]);
						}
					}
					listener2.pop();
				}
				day++;
			}
		}
	}
	while (!rumorList.empty()) {
		out << rumorList.front() << endl;
		rumorList.pop();
	}
}
