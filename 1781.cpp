#include <iostream>
#include <cstring>

void shift(char s[], int shiftV, int shiftC) {
	// tam: length of the string
	// j: iterator for vowels
	// k: iterator for consonats
	// posV: save the position of the vowels by its index
	// posC: save the position of the consonants by its index
	int tam = strlen(s),j = 0, k = 0, posV[tam], posC[tam];
	char vowel[tam], consonant[tam];

	// maps the vowels and consonants of the string
	for(int i = 0; i < tam; i++) {
		if(s[i] == 'a' | s[i] == 'e' | s[i] == 'i' | s[i] == 'o' | s[i] == 'u') {
			vowel[j] = s[i];
			posV[j] = i;
			j++;
		}
		else {
			consonant[k] = s[i];
			posC[k] = i;
			k++;
		}
	}

	// make the shifts
	for(int i = 0; i < j; i++) 
		s[posV[(i + shiftV) % j]] = vowel[i];
	for(int i = 0; i < k; i++) 
		s[posC[(i + shiftC) % k]] = consonant[i];

	std::cout << s << std::endl;
}

int main() {
	// op: takes the operations
	// d: adds how many shifts will be done
	// shiftV: sums all vowel's shifts
	// shiftC: sums all consonants' shifts
	int t, q, op, d, shiftV, shiftC;
	char s[100001];

	std::cin >> t;
	for(int i = 0; i < t; i++) {
		std::cout << "Caso #" << i + 1 << ":" << std::endl;

		std::cin >> s;
		std::cin >> q;

		d = 0; shiftV = 0; shiftC = 0;
		for(int j = 0; j < q; j++) {
		
			std::cin >> op;
			if(op != 2) {
				std::cin >> d;
				if(op == 0)
					shiftV += d;
				else
					shiftC += d;
			}
			else {
				// make the shifts just when the print operation is called
				shift(s, shiftV, shiftC);
				d = 0; shiftV = 0; shiftC = 0;
			}
		}
	}
	return 0;
}