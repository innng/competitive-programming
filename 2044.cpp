#include <iostream>

int main(int argc, char const *argv[]) {
	int n;

	std::cin >> n;
	while(n != -1) {
		int p[n], count = 0, times = 0;

		for (int i = 0; i < n; i++) {
			std::cin >> p[i];
			count += p[i];

			if(count % 100 == 0)
				times++;
		}

		std::cout << times << std::endl;
		std::cin >> n;
	}

	return 0;
}