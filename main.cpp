#include "simplestring.h"
#include "interview.h"
#include "singleton.h"

using namespace std;
using namespace simplestd;


#include <stdio.h>
#include <string.h>

#include "stdio.h"
char* humpDel1(const char* src, char* des)//只删除中间的
{
	int i, j;
	for (i = 1, j = 1, des[0] = src[0]; src[i + 1] != 0; i++)
	{
		if (!(src[i - 1] == src[i + 1] && src[i] != src[i + 1]))//src[i] is not hump
			des[j++] = src[i];
	}
	des[j++] = src[i];
	des[j] = 0;
	return des;
}
char* humpDel3(const char* src, char* des)//3个都删除
{
	int i = 0, j = 0, flen = 0;
	char* flag;
	while (src[flen] != 0)
		flen++;
	flag = (char*)malloc(flen*sizeof(char));
	for (i = 0; i < flen; i++)
		flag[i] = 1;
	for (i = 0; src[i + 2] != 0; i++)
	{
		if (src[i] == src[i + 2] && src[i] != src[i + 1])
		{
			flag[i] = 0;
			flag[i + 1] = 0;
			flag[i + 2] = 0;
		}
	}
	for (i = 0, j = 0; i < flen; i++)
	{
		if (flag[i])
			des[j++] = src[i];
	}
	des[j] = 0;
	free(flag);
	return des;
}

int main()
{
	//char a[] = { "aabababbABaaacAcAcBCdCdCa" };
	char a[] = { "aoelelod world" };
	char b[100];//1.aabbABaaaccBCC,3.abABaaaBa
	humpDel3(a, b);
	printf("src=%s\n", a);
	printf("des=%s\n", b);
	system("pause");
}

/*
int main()
{
	char buffer[80] = "aoelelod world";
	for (int i = 0; buffer[i] != '\0'; i++){
		if (buffer[i + 2] == '\0'){
			printf("ok");
			printf("%c\n", buffer[i]);
			return 0;
		}
		if (buffer[i] == buffer[i + 2] && buffer[i] != buffer[i + 1]){
			int j = i;
			while (buffer[j + 3] != '\0'){
				buffer[j] = buffer[j + 3];
				j++;
			}
			buffer[(j + 2)] = '\0';
			if ((i - 1) > 0){
				i = i - 1;
			}
		}
		printf("%c/n", buffer[i]);
	}
	return 0;
}
*/
