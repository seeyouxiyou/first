//判断输入是否为4的幂
#include<stdio.h>

int isPowerOfFour(int num) {
    return (num > 0) && ((num & num-1) == 0) && ((num & 0x55555555) == num);
}

int main()
{
	int i, ret;
	printf("input value\n");
	scanf("%d", &i);

	ret = isPowerOfFour(i);

	if(ret == 1)
		printf("1\n");
	else
		printf("-1\n");


	return 1;

}
