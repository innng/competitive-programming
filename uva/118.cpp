#include <bits/stdc++.h>
 
using namespace std;

map<char, int> dir1;
map<int, char> dir2;
int x_upper_right, y_upper_right;
int x, y, lost;
int scent[50][50] = {0};
char pos;

void move(char* instr) {
	int len = strlen(instr);

	lost = 0;

	for(int i = 0; i < len; i++) {
		if(instr[i] == 'L') {
			int index = dir1[pos];
			int new_pos = (index + 3) % 4;
			pos = dir2[new_pos];
		} else if(instr[i] == 'R') {
			int index = dir1[pos];
			int new_pos = (index + 1) % 4;
			pos = dir2[new_pos];
		} else {	
			switch(pos) {
				case 'N': 
					if(y == y_upper_right) {
						if(scent[x][y] != 1) {
							lost = 1;
							scent[x][y] = 1;
						} else continue;
					} else 
						y += 1;
					break;
				case 'E': 
					if(x == x_upper_right) {
						if(scent[x][y] != 1) {
							lost = 1;
							scent[x][y] = 1;
						} else continue;
					} else 
						x += 1;
					break;
				case 'S': 
					if(y == 0) {
						if(scent[x][y] != 1) {
							lost = 1;
							scent[x][y] = 1;
						} else continue;
					} else 
						y -= 1;
					break;
				case 'W': 
					if(x == 0) {
						if(scent[x][y] != 1) {
							lost = 1;
							scent[x][y] = 1;
						} else continue;
					} else 
						x -= 1;
					break;
			}
		}

		if(lost)
			break;
	}

	if(lost)
		printf("%d %d %c LOST\n", x, y, pos);
	else
		printf("%d %d %c\n", x, y, pos);
}

int main() {
	dir1['N'] = 0; dir2[0] = 'N';
	dir1['E'] = 1; dir2[1] = 'E';
	dir1['S'] = 2; dir2[2] = 'S';
	dir1['W'] = 3; dir2[3] = 'W';

	cin >> x_upper_right >> y_upper_right;

	while(cin >> x >> y >> pos) {
		char instr[100];
		cin >> instr;

		move(instr);
	}

	return 0;
}
