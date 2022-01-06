#include<stdio.h>
#define MAX 40 + 1
int fib[MAX][2];
void get_fib(int);

int main() {
	int t, n;

	scanf("%d", &t);
	
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
    
		if (n > 1) get_fib(n);
    
		printf("%d %d\n", fib[n][0], fib[n][1]);
	}
	return 0;
}

//DP를 활용해 피보나치 수 구하기
void get_fib(int n) {
	fib[0][0] = 1;
	fib[0][1] = 0;
	fib[1][0] = 0;
	fib[1][1] = 1;
  
	for (int i = 2; i < n + 1; i++) {
		fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
		fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
	}
}
