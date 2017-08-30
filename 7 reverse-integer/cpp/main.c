#include <stdio.h>
#include <limits.h>

int reverse(int x) {
	int sign = x < 0 ? -1 : 1;
	x *= sign;

	long long rev = 0;
	while (x > 0) {
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	rev *= sign;
	return (rev > INT_MAX || rev < INT_MIN) ? 0: rev;
	// return rev;
}

int main(void) {
	// printf("%d\n", reverse(-9999241365));
	printf("%d\n", reverse(4041356));
	// overflow:
	printf("%d\n", reverse(1534236469));

	printf("~0 = %d\n", ~0u);
	printf("~1 = %d\n", ~1);
	
	return 0;
}