#include<stdio.h>
#include<sys/resource.h>
#include<time.h>
#include<sys/time.h>

void warshall (int r[][5], int n)
{
	int i, j, k;

	for (k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				r[i][j] = r[i][j] || (r[i][k] && r[k][j]);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d\t", r[i][j]);
		printf("\n\n");
	}
}

int main ()
{
	struct timeval tv1, tv2;
	struct rusage r_usage;
	int i, j, n, a[5][5];
	printf("Enter size\n");
	scanf("%d", &n);
	printf("Enter matrix elements:\n");
	for ( i = 0; i < n; i++ )
		for(j=0; j < n; j++)
		{
			scanf ("%d", &a[i][j]);
		}
	printf ("Given matrix\n");
	for ( i = 0; i < n; i++ )
	{
		for(j = 0; j < n; j++)
		{
			printf ("%d\t", a[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
	gettimeofday (&tv1, NULL);
	warshall(a, n);
	gettimeofday (&tv2, NULL);
	printf ("Time of Warshall's algorithm = %f microseconds\n", (double)(tv2.tv_usec - tv1.tv_usec));
	getrusage (RUSAGE_SELF, &r_usage);
	printf ("Memory usage %ld kilobytes\n", r_usage.ru_maxrss);
}
