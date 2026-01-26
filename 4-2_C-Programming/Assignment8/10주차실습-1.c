#include <stdio.h>

int check_prime(int n) {
	int is_prime = 1;
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) {
			is_prime = 0;
			break;
		}
	}
	return is_prime;
}

int main(void) {
	for (int i = 2; i <= 100; ++i) {
		if (check_prime(i)) printf("%d ", i);
	}

	return 0;
}