//查找源字符串数组中(已排序)，是否包含目的字符串的前缀。头条题库
//大数据量查找应该用二分确定起始字符的位置
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000

int main(int argc, char **argv){
    
    if(argc != 3)
    {
        printf("usage!\n");
        return -1;
    }

    int arrlen = atoi(argv[1]);
    int retlen = atoi(argv[2]);
    int i = 0;
    int j = 0;
    int k = 0;
	int flag = 0;
    
    char arr[arrlen][MAXLEN];
    char arrg[retlen][MAXLEN];
    int ret[retlen];
   
    while(i < arrlen)
    {
		scanf("%s", arr[i++]);
    }
    
    while(j < retlen)
    {
		scanf("%s", arrg[j++]);
    }

    
    for(i = 0; i < retlen; i++)
    {
        for(j = 0; j < arrlen; j++)
        {
			flag = 1;
			k = 0;
			if(strlen(arr[j]) > strlen(arrg[i]))
			{
				flag = 0;
				continue;
			}
			
			while(arr[j][k] != '\0')
			{
				if(arr[j][k] != arrg[i][k])			
				{
					flag = 0;
					break;
				}
				k++;
			}
			if(flag == 1)
				break;
        }

		if(flag == 1)
			ret[i] = 1;
		else
			ret[i] = -1;
    }

     for(i = 0; i < retlen; i++)
     {
	 	printf("%d\n", ret[i]);
     }
    
    return 0;
}

