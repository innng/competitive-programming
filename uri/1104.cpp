#include <iostream>
#include <cstdlib>

int compare(const void *a, const void *b) {
	if(*(int*)a < *(int*)b)
		return -1;
	if(*(int*)a > *(int*)b)
		return 1;
	else return 0;
}

int main(int argc, char const *argv[]) {
	int a, b, total = 0;

	while(1) {
		std::cin >> a >> b;

		// end of input
		if(a == 0 && b == 0)
			break;

		int x[a], y[b];

		// a's cards
		for(int i = 0; i < a; i++)
			std::cin >> x[i];

		// b's cards
		for(int i = 0; i < b; i++)
			std::cin >> y[i];

		// sorting the cards in ascending order
		qsort(x, a, sizeof(int), compare);
		qsort(y, b, sizeof(int), compare);

		// counts how many unique cards in each deck
		int singleA = 0, singleB = 0;
		// parts the unique c
		int singleX[a], singleY[b];

		for(int i = 0; i < a; i++)
			if(x[i] != x[i - 1]) {
				singleX[singleA] = x[i];
				singleA++;
			}

		for(int i = 0; i < b; i++)
			if(y[i] != y[i - 1]) {
				singleY[singleB] = y[i];
				singleB++;
			}

		// checks what is the bottleneck
		int max = singleA < singleB ? singleA : singleB;
		// counts how many equal cards
		int equal = 0;

		for(int i = 0; i < singleA; i++)
			for(int j = 0; j < singleB; j++)
				if(singleX[i] == singleY[j])
					equal++;

		// the total of trading card is the bottleneck deck minus the equal cards bettwen decks
		total = max - equal;
		std::cout << total << std::endl;
	}

	return 0;
}