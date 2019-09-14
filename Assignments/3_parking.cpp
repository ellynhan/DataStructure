#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream readFile("parking.inp");
	int lot, num;
	readFile >> lot >> num;
	vector<int> pl(lot);
	int numberCount = 0;
	int car, current_lot, current_car = 0;
	
	while (numberCount<num) {
		current_lot = pl.size();
		int countReset = 0;
		for (int i = 0; i<current_lot; i++) {
			if (pl.at(i) != 0) {
				countReset++;
			}
		}
		current_car = countReset;
		readFile >> car;
		if (car>0) {
			if (current_lot != current_car) {
				for (int i = 0; i < current_lot; i++) {
					if (pl.at(i) == 0) {
						pl[i] = car;
						current_car++;
						break;
					}
				}
			}
			else {
				pl.resize(current_lot * 2, 0);
				pl[current_car] = car;
				current_car++;
			}
		}
		else if (car<0) {
			for (int i = 0; i<current_lot; i++) {
				if (pl.at(i) == (-car)) {
					pl[i] = 0;
					current_car--;
					break;
				}
			}
			if (current_lot>lot) {
				if (current_lot / 3 >= current_car) {
					int* tmp = new int[current_car];
					int j = 0;
					for (int i = 0; i<current_lot; i++) {
						if (pl.at(i) != 0) {
							tmp[j++] = pl.at(i);
						}
					}
					for (int i = 0; i<current_lot; i++) {
						pl.pop_back();
					}
					pl.resize(current_lot / 2, 0);
					current_lot = current_lot / 2;
					for (int i = 0; i<current_car; i++) {
						pl[i] = tmp[i];
					}
				}
			}
		}
		numberCount++;
	}
	readFile.close();
	ofstream outFile("parking.out");
	int k = 1;
	for (int i = 0; i<current_lot; i++) {
		if (pl.at(i) != 0) {
			outFile << i+1 << " " << pl[i];
			if(k<current_car)
                outFile<<endl;
            k++;
		}
	}
	outFile.close();
}
