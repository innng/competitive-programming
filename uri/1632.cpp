#include <iostream>
#include <string>

using namespace std;

int main(){
	int t, numComb;
	string entrada;
	int letras[26];

	for(int i=0; i<26; i++)
		letras[i] = 2;
	letras[0]=letras[4]=letras[8]=letras[14]=letras[18]=3;

	cin >> t;
	while(numComb = 1, t--){
		cin >> entrada;
		for(int i=0; i<entrada.size(); i++)
			numComb *= letras[(int)toupper(entrada[i])-65];
		cout << numComb << endl;
	}
	
	return 0;
}