//判断输入是否为4的幂
#include<stdio.h>

int isPowerOfFour(int num) {
    if (num == 1)
        return 1;
    int i = 0;
    unsigned int sum = 4;
    for(;i < 15; i++)
        sum += sum << 2;
    
    if((num & sum) == num)
        return 1;
    return -1;
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
