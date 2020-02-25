#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>

void heapsort (int h[], int n);

int main ()
{
	struct timeval tv1, tv2;
	struct rusage r_usage;
	int i, n, arr[10];
	printf("Enter number of students\n");
	scanf("%d", &n);
	printf("Enter student ids:\n");
	for ( i = 1; i <= n; i++ )
	{
		scanf ("%d", &arr[i]);
	}
	printf ("Unsorted array\n");
	for ( i = 1; i <= n; i++ )
	{
		printf ("%d", arr[i]);
	}
	printf("\n");
	gettimeofday (&tv1, NULL);
	MaxHeap (arr, n);
	gettimeofday (&tv2, NULL);
	printf ("Sorted array\n");
	for ( i = 1; i <= n; i++ )
	{
		printf ("%d\t", arr[i]);
	}
	printf ("\n");
	printf ("Time of selection sort = %f microseconds\n", (double)(tv2.tv_usec - tv1.tv_usec));
	getrusage (RUSAGE_SELF, &r_usage);
	printf ("Memory usage %ld kilobytes\n", r_usage.ru_maxrss);
}

void MaxHeap (int h[], int n)
{
	int temp, i;
	/*
	temp = h[1];
	h[1] = h[n];
	h[n] = temp;
*/

	for (i = n; i >= 1; i--)
	{
		heapsort (h,i);
		temp = h[1];
		h[1] = h[i];
		h[i] = temp;
	}
}


void heapsort (int h[20], int n)
{
	int i, j, k, heap, v;
	for (i = n/2; i >= 1; i--)
	{
		k = i;
		v = h[k];
		heap = 0; // 0 for false
		while (!heap && 2*k <= n)
		{
			j = 2*k;
			if(j < n)
			{
				if (h[j] < h[j+1])
					j = j + 1;
			}
			if (v >= h[j])
				heap = 1;
			else
			{
				h[k] = h[j];
				k = j;
			}
			h[k] = v;
		}
	}
}
