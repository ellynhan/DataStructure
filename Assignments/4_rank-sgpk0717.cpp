#include <bits/stdc++.h>
using namespace std;
main(void) {
	int N, score, i, j;
	cin >> N;
	vector<vector<int> >v(N);
	for (i = 0; i<N; ++i) {
		v[i].push_back(-2); //�� �հ��� ����η����� ��.
		cin >> score;
		for (j = 0; score != -1; ++j) {
			v[i].push_back(score);
		}//���� ����
		v[i][0] = j;//�Ǿ� ������ ���� ���� ��������
		v[i].push_back(-i - 1);//�ǵڿ� -(�л���ȣ+2) ����
	}
	for (i = 0; i < N; ++i) {
		sort(v[i].begin() + 1, v[i].end() - 1);
	}
	sort(v.begin(), v.end(), greater<vector<int> >());

	for (i = 0; i < N; ++i) {
		cout << -v[i][v[i][0] + 1] << endl;
	}
}