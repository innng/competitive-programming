//https://www.urionlinejudge.com.br/judge/pt/problems/view/1257
#include <iostream>

using namespace std;

int main(){
	int qtdTestes, linhas, valorHash = 0;
	string palavra;

	cin >> qtdTestes;

	for(int i=0; i<qtdTestes; i++){
		cin >> linhas;
		for(int j=0; j<linhas; j++){
			cin >> palavra;
			for(int k=0; k<palavra.size(); k++){
				valorHash += (palavra[k] - 65) + j + k;
			}
		}
		cout << valorHash << endl;
		valorHash = 0;
	}


	return 0;
}