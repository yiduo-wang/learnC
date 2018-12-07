#include<stdio.h>
#include<stdlib.h>

#define N 11

int main()
{
	//int A = 0, B = 0, C = 0, D = 0, E = 0;
	//for (A = 1; A <= 5; ++A)
	//{
	//	for (B = 1; B <= 5; ++B)
	//	{
	//		for (C = 1; C <= 5; ++C)
	//		{
	//			for (D = 1; D <= 5; ++D)
	//			{
	//				for (E = 1; E <= 5; ++E)
	//				{
	//					if ((B == 2 || A == 3)  && (B == 2 || E == 4) && (C == 1 || D == 2)  && (C == 5 || D == 3) && (E == 4 || A == 1) )
	//					{
	//						if(A*B*C*D*E==120)
	//							printf("A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}


	//int A = 0, B = 0, C = 0, D = 0;
	//for (A = 0; A <= 1; ++A)
	//{
	//	for (B = 0; B <= 1; ++B)
	//	{
	//		for (C = 0; C <= 1; ++C)
	//		{
	//			for (D = 0; D <= 1; ++D)
	//			{
	//				if((A==0&&C==1&&D==0)+(A==0&&C==1&&D==1)+(A==0&&D==1&&D==0)+(C==1&&D==1&&D==0))
	//				{
	//					if(A+B+C+D==1)
	//						printf("A=%d,B=%d,C=%d,D=%d\n", A,B,C,D);
	//				}
	//			}
	//		}
	//	}
	//}

	//char killer;
	//for (killer = 'A'; killer < 'D'; ++killer)
	//{
	//	if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') )== 3)
	//		printf("%c\n", killer);
	//	
	//}

	int arr[N][N];
	int i = 0, j = 0;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j <= i; ++j)
		{
			arr[i][0] = 1;
			arr[i][i] = 1;

		}
	}
	for (i = 2; i < N; ++i)
	{
		for (j = 1; j < i; ++j)
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
	}
	for (i = 0; i < N; ++i)
	{
		//for (j = 0; j <=2*(N - i); ++j)
		//	printf(" ");
		for (j = 0; j <= i; ++j)
			printf("%-3d ", arr[i][j]);
		printf("\n");
	}
	system("pause");
}