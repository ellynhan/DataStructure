#include <iostream>
using namespace std;
int row=0,col=-1,s=1,j=0;

void upside(int** grid,int m){
	col++;
    for(int i=0; i<m-(j/2); i++){
        grid[col][row]=s;
        col++;
        s++;
    }
    col--;
}
void rightside(int** grid,int n){
    row++;
    for(int i=0; i<n-(j/2); i++){
        grid[col][row]=s;
        row++;
        s++;
    }
    row--;
}
void downside(int** grid,int m){
    col--;
    for(int i=0; i<m-(j/2); i++){
        grid[col][row]=s;
        col--;
        s++;
    }
    col++;
}
void leftside(int** grid,int n){
    row--;
    for(int i=0; i<n-(j/2); i++){
        grid[col][row]=s;
        s++;
        row--;
    }
    row++;
}


int main(){
    int n,m;
    cin>>n>>m;
	int x, y;
	cin >> x >> y;
	int N;
	cin >> N;
    int** grid=new int*[m];
    for(int r=0; r<m; r++){
        grid[r]=new int[n];
    }
    while(s!=m*n+1){
        if(s<m*n+1){
            j++;
            upside(grid,m);
        }
        if(s<m*n+1){
            j++;
            rightside(grid,n);
        }
        if(s<m*n+1){
            j++;
            downside(grid,m);
        }
        if(s<m*n+1){
            j++;
            leftside(grid,n);
        }
    }
	cout << grid[y - 1][x - 1] << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == N) {
				cout << j + 1 << " " << i + 1;
				break;
			}
		}
	}

}
