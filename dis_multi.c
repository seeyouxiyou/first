//目的为查找差值为2的值对的个数，值进行去重
#include<stdio.h>

void insert_sort();

int main(int argc, char **argv)
{
	int n, m, i, j;
	int k = 0;
	printf("pls input arr len:\n");
	scanf("%d", &n);
	printf("pls input sub val:\n");
	scanf("%d", &m);

	int arr[n];
	printf("pls input arr val:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	//排序不去重
	insert_sort(arr, n);

	for(i = 0; i < n; i++)
	{
		if(arr[i] == arr[i+1])
			continue;
		for(j = i; j < n; j++)	
		{
			if(arr[i] == arr[j] - m)	
			{
				k++;
				break;	
			}
		}
	}

	printf("there are %d couple \n", k);

	return 0;
}

void insert_sort(int *arr, int n)
{
	int i, j;

	for(i = 1; i < n; i++)
	{
		for(j = i; j > 0; j--)	
		{
			if(arr[j] < arr[j-1])	
			{
				arr[j] += arr[j-1];	
				arr[j-1] = arr[j] - arr[j-1];
				arr[j] = arr[j] - arr[j-1];
			}
		}
	}
}
