//计算器
#include <stdio.h>

int main(void) {
	int a, b, flag;
	char op;
	scanf("%d", &a);
	do {
		scanf("%c", &op);
		if (op == '+') {
			scanf("%d", &b);
			a = a + b;
		}
		else if (op == '-') {
			scanf("%d", &b);
			a = a - b;
		}
		else if (op == '*') {
			scanf("%d", &b);
			a = a * b;
		}
		else if (op == '/') {
			scanf("%d", &b);
			if (b == 0)	flag = 1;    //字母为0.
			else {
				a = a / b;
				flag = 0;
			}
		}
		else if (op == '=')	break;    //等号退出。
		else	flag = 1;    //非法字符。
	} while (1);
	if (flag)	printf("ERROR");
	else	printf("%d", a);

	return 0;
}

//判断上三角矩阵
#include <stdio.h>

void delta(int n, int arr[10][10]);
int main(void) {
	int T, n, i, j, k;
	int arr[10][10];

	scanf("%d", &T);
	for (k = 0; k < T; k++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		delta(n, arr);
	}

	return 0;
}

void delta(int n, int arr[10][10]) {
	int i, j, flag;

	flag = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if (i > j && arr[i][j] != 0) {
				flag = 0;
				break;
			}
		}

	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
}

//找鞍点
#include <stdio.h>
#define MAXN 6

int main(void) {
	int n, i, j, k, row, col, flag;
	int a[MAXN][MAXN];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	for (i = 0; i < n; i++) {
		col = 0, flag = 1;
		for (j = 0; j < n; j++) {
			if (a[i][col] <= a[i][j])
				col = j;
		}
		for (k = 0; k < n; k++) {
			if (a[i][col] > a[k][col]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			row = i;
			break;
		}
	}

	if (flag)
		printf("%d %d", row, col);
	else
		printf("NONE");

	return 0;
}

