#include <bits/stdc++.h>
using namespace std;
main(void) {
	int N, score, i, j;
	cin >> N;
	vector<vector<int> >v(N);
	for (i = 0; i<N; ++i) {
		v[i].push_back(-2); //맨 앞공간 비워두려고한 것.
		cin >> score;
		for (j = 0; score != -1; ++j) {
			v[i].push_back(score);
		}//점수 서장
		v[i][0] = j;//맨앞 공간에 과제 제출 개수저장
		v[i].push_back(-i - 1);//맨뒤에 -(학생번호+2) 넣음
	}
	for (i = 0; i < N; ++i) {
		sort(v[i].begin() + 1, v[i].end() - 1);
	}
	sort(v.begin(), v.end(), greater<vector<int> >());

	for (i = 0; i < N; ++i) {
		cout << -v[i][v[i][0] + 1] << endl;
	}
}