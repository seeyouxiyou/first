//将数组中偶数排在前，奇数排在后
#include<stdio.h>
#include<stdlib.h>

//原地排序
int* resort(int *arr, int len)
{
	int i, j;

	for(i = 0, j = 0; i < len && j < len; i++, j++)
	{
		while(arr[i] % 2 != 0 && i < len)//找到顺序第一个偶数下标
			i++;
		while(arr[j] % 2 == 0 && j < len)//找到顺序第一个奇数下标
			j++;

		if(i > j && i < len) //如果偶数下标大于奇数下标交换
		{
			arr[i] += arr[j];	
			arr[j] = arr[i] - arr[j];
			arr[i] = arr[i] - arr[j];
		}
	}
		return arr;
}

//非原地排序
int * resort1(int *arr, int len)
{
	int ret[len];
	int i, j, k = 0;
	j = len;

	for(i = 0; i < len; i++)
	{
		if(arr[i] % 2 == 0)	
			ret[k++] = arr[i];	
		else
			ret[len-1-k] = arr[i];
	}

	for(i = 0; i < j; i++)
		printf("%d ", ret[i]);
	printf("\n");

	return arr;

}

int main()
{
	int len;
	int i, j;
	int *arr, *ret;

	printf("input arr length:\n");
	scanf("%d", &len);

	arr = malloc(sizeof(int)*len);
	ret = malloc(sizeof(int)*len);

	printf("input arr val:\n");
	for(i = 0; i < len; i++)
		scanf("%d",&arr[i]);

//	ret = resort(arr, len);

	ret = resort1(arr, len);

	for(i = 0; i < len; i++)
		printf("%d ", arr[i]);

	return 0;
}
