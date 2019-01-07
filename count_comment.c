//统计文章的注释个数
//头条
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 1000
//
//   /*
/*
 */
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("usage!\n");	
		return -1;
	}

	FILE *p;
	char *line = malloc(100000);
	char *temp = malloc(100000);
	int count = 0;
	int flag = 0;// comment /* status
	int len;

	p = fopen(argv[1], "r+");
	if(!p)
	{
		printf("file open error!\n");	
		return -1;
	}

	while(!feof(p))
	{
		fgets(line, 10000, p);
		len = strlen(line);
//		*(line+len-1) = '\0';
		
		if(flag)
		{
			if(strstr(line, "*/"))
			{
				line = line+2;
				flag = 0;
			}
			else
				continue;
		}
		while(*line != '\0')
		{
		if(*line == '"')
		{
			line++;	
			line = strchr(line, '"');
			line++;
		}
		else if(*line == '/' && *(line+1) == '/')
		{
			count++;
			line++;
			break;
		}
		else if(*line == '/' && *(line+1) == '*')
		{
			flag = 1;
			count++;
			line++;
			continue;
		}
		else if(*line == '\'')
		{
			if(*(line+1) == '\\')	
				line += 3;
			else 
				line += 2;
		}
		else
			line++;
		
		}
	}

	printf("there are %d comments in file %s\n", count, argv[1]);

	return 0;
	
}
