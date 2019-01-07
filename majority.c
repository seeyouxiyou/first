//找众数，出现次数大于三分之一的数字
#include<stdio.h>
#include<stdlib.h>

int* majorityElement(int* nums, int numsSize, int *returnSize) {
    if(nums == NULL || numsSize == 0)
        return NULL;
    int *ans = (int *)malloc(sizeof(int) * (*returnSize));
    if(numsSize == 1)
    {
        //ans[0] = nums[0];
		*returnSize = 1;
        return nums;
    }
        
    int num, i;
    int n1 = nums[0];
    int n2 = 0;
    int c1 = 1;
    int c2 = 0;
    
    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] == n1)
            c1++;
        else if(nums[i] == n2)
            c2++;
        else if(n1 == 0)
        {
            n1 = nums[i];
            c1++;
        }
        else if(n2 == 0)
        {
            n2 = nums[i];
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    
    c1 = 0;
    c2 = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(n1 == nums[i])
            c1++;
        else if(n2 == nums[i])
            c2++;
    }
    
    i = 0;
    if(c1 > (numsSize/3))
    {
        ans[i] = n1;
        i++;
    }
    if(c2 > (numsSize/3) )
	{
        ans[i] = n2;
		i++;
	}
	//printf("c1, c2:%d %d\n", c1,c2);

    *returnSize = i;    
    return ans;
}

int main()
{
	int size = 2;
	int len;
	int i = 0;

	printf("input length of array:\n");
	scanf("%d", &len);
	int arr[len];

	printf("input value of array:\n");
	while(i < len)
		scanf("%d", &arr[i++]);

	int *res = majorityElement(arr, len, &size);
	i = 0;
	while(i < size)
	{
		printf("majority %d: %d\n", i, res[i]);
		i++;
	}
	
	return 0;
}

