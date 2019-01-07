//josephus question
//问题变种输入描述：
//第一行是一个正整数N，表示有N组参数。
//
//从第二行开始，每行有若干个正整数，依次存放 n,m,A1,A2,…Amn,m,A1,A2,…Am，共有N行，也就是上面的N组参数。
//
//输出描述：
//输出有N行，每行对应相应的那组参数确定的录取之人的编号
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
		/*
	if(argc != 2)
	{
		printf("usage!\n");	
		return -1;
	}

	int n; //n组参数
	n = atoi(argv[1]); // 先只支持1组参数
*/
	int amount; //参赛人数
	printf("input participators:\n");
	scanf("%d", &amount);

	int nums;
	printf("input nums' len:\n");
	scanf("%d", &nums);
	
	int m[nums];
	printf("input nums:(num > 0)\n");
	int i = 0;
	int flag[amount];
	while(i < nums)
	{
		scanf("%d", &m[i++]);
	}

	int j = 0;
	int temp;
	//初始化标记位，1表示未淘汰
	for(i = 0; i < amount; i++)
		flag[i] = 1;	

	for(i = amount; i > 1; i--)
	{
		temp = m[j%nums] - 1;
		while(flag[temp % amount] == 0)
		{
			temp++;	
		}
		flag[temp%amount] = 0;
	}

	for(i = 0; i < amount; i++)
		if(flag[i] == 1)
			printf("index is %d\n", i);

	return 0;
}
