//指针申请内存大小根据数据结构来设置，方便之处在于地址的传递只需要一个指针大小的内存，提高传输效率
#include<stdio.h>
#include<stdlib.h>


int main()
{
	char *n;
	char *m;
	printf("%d %d\n", sizeof(char*), sizeof(int*));
	n = (char *)malloc(sizeof(char *));
	m = (char *)malloc(sizeof(char *));

	for(int i = 0; i < 20; i++)
		n[i] = '1';
	for(int i = 0; i < 20; i++)
		m[i] = '2';

	for(int i = 0; i < 20; i++)
		printf("%c ", *(n+i));

	printf("\n");

	for(int i = 0; i < 20; i++)
		printf("%c ", *(m+i));

	printf("\n");
	printf("%p\n%p\n", n, m);
	printf("\n");

	return 0;
}
