#include<stdio.h>
#include<stdlib.h>

void quickSort(int a[], int left, int right)
{
	if(NULL == a || left < 0 || right < 0 || left > right)
		return;

	if(left < right)
	{
		int key = a[left];
		int low = left;
		int high = right;
		
		while(low < high)
		{
			while(low < high && a[high] >= key)
			{
				--high;
			}
			a[low] = a[high];

			while(low < high && a[low] <= key)
			{
				++low;
			}
			a[high] = a[low];
		}
		a[low] = key;
		quickSort(a, left, low-1);
		quickSort(a, low+1, right);
	}
}

void bubbleSort(int a[], int n)
{
	int i, j, temp;

	for(j = 0; j < n - 1; j++)
	{
		for(i = 0; i < n - 1 - j; i++)
		{
			if(a[i] > a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
}

int main()
{
	int a[]={0, 3, 1, 2, 4, 2, 90, 34, 54};

	int length = sizeof(a)/sizeof(a[0]);

	//quickSort(a, 0, length-1);
	bubbleSort(a, length);

	for(int i = 0; i < length; i++)
	{
		printf("a[%d] = %d\n",i,a[i]);
	}

	system("pause");

	return 0;
}