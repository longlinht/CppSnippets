#include "simplestring.h"
#include "interview.h"
#include "singleton.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdio.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;
using namespace simplestd;

char* humpDel1(const char* src, char* des)
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
char* humpDel3(const char* src, char* des)
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

/*
int main()
{
    do
    {
        std::string sub;
        iss >> sub;
        if(!sub.empty())
            std::cout << "Substring: " << sub << std::endl;
    } while (iss);

	//char a[] = { "aabababbABaaacAcAcBCdCdCa" };
	char a[] = { "aoelelodworld" };
    std::string s = "abc d e f";
    std::string d;
    replaceSpaces(s, d);
    std::cout<<d<<std::endl;
    s.append("a");

	printf("orig=%s\n", a);
    removeDuplicates(a);
	printf("now=%s\n", a);

    int a[][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            std::cout<<a[i][j]<<" ";
        std::cout<<std::endl;
    }

    std::cout<<"Before transpose"<<std::endl;

    transpose(a, 4);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            std::cout<<a[i][j]<<" ";
        std::cout<<std::endl;
    }

    int a[] = {4,9,10, 22, 1,8,5};
    std::cout<<"before sort"<<endl;
    for(int i=0; i < 7; i++) {
        cout<<a[i]<<" ";
    }
    std::cout<<endl;

    //selectSort(a,7);
    //insertSort(a,7);
    quickSort(a,0,6);

    std::cout<<"after sort"<<endl;
    for(int i=0; i < 7; i++) {
        cout<<a[i]<<" ";
    }
    std::cout<<endl;
}
*/

int main()
{
    /*
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
    */

    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);

    bool isMopPrime = (isMopNumber(n)) && (isPrimeNumber(n));
    cout<<"is mop prime=" << isMopPrime<<endl;

    return 0;
}
