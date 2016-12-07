#include <stdio.h>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <cctype>
#include <assert.h>
#include "interview.h"

size_t slenth(const char *s){
	if (NULL == s)
		return 0;
	const char *p = s;
	size_t len = 0;
	while (*p++ != '\0')
		++len;
	return len;
}

void reverse(char *b){
	char c;
	int j;
	size_t len;
	len = strlen(b);
	j = len / 2 - 1;
	while (j >= 0)
	{
		c = *(b + j);
		*(b + j) = *(b + len - j - 1);
		*(b + len - j - 1) = c;
		j--;
	}
	b[len] = '\0';
}

void reverseWithPtr(char* s)
{
	assert(s != NULL);

	char* beg = s;
	char* end = s;
	while (*end != '\0')
	{
		end++;
	}

	end--;

	while (beg < end)
	{
		char t = *beg;
		*beg = *end;
		*end = t;
		beg++;
		end--;
	}
}

void insertSort(int arr[], size_t size){
	size_t i, j;
	int tmp;
	for (i = 1; i < size; ++i){
		tmp = arr[i];
		j = i - 1;
		while ((j >= 0) && arr[j] > tmp){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
}

void merge_array(int *list1, int list1_size, int *list2, int list2_size){
	int i, j, k;
	i = j = k = 0;

	int *list = (int*)malloc((list1_size + list2_size)*sizeof(int));

	while (i < list1_size && j < list2_size){
		list[k++] = list1[i] < list2[j] ? list1[i++] : list2[j++];
	}

	while (i < list1_size){
		list[k++] = list1[i++];
	}

	while (j < list2_size){
		list[k++] = list2[j++];
	}

	for (int ii = 0; ii < (list1_size + list2_size); ++ii){
		list1[ii] = list[ii];
	}
	free(list);
}

void merge_sort(int *list, int list_size){
	if (list_size > 1){
		int *list1 = list;
		int list1_size = list_size / 2;
		int *list2 = list + list_size / 2;
		int list2_size = list_size - list1_size;

		merge_sort(list1, list1_size);
		merge_sort(list2, list2_size);

		merge_array(list1, list1_size, list2, list2_size);
	}
}

void radixSort(int a[], size_t n){
	int i, m = a[0], exp = 1;
	int b[20] = { 0 };

	//Get the greatest value in the array a and assign it to m
	for (i = 1; i < n; i++){
		if (a[i] > m)
			m = a[i];
	}

	//Loop until exp is bigger than the largest number
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };

		//Count the number of keys that will go into each bucket
		for (i = 0; i < n; i++)
			bucket[(a[i] / exp) % 10]++;

		//Add the count of the previous buckets to acquire the indexes after the end of each bucket location in the array
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1]; //similar to count sort algorithm i.e. c[i]=c[i]+c[i-1];

		//Starting at the end of the list, get the index corresponding to the a[i]'s key, decrement it, and use it to place a[i] into array b.
		for (i = n - 1; i >= 0; i--)
			b[--bucket[(a[i] / exp) % 10]] = a[i];

		//Copy array b to array a
		for (i = 0; i < n; i++)
			a[i] = b[i];

		//Multiply exp by the BASE to get the next group of keys
		exp *= 10;
	}
}

void countASIICs(const char *s){
	char asc[256];

	for (int i = 0; i < 256; i++){
		asc[i] = 0;
	}

	while (*s != '\0'){
		asc[*s++]++;
	}

	for (int i = 0; i < 256; i++){
		printf("%d ", asc[i]);
	}
}



void printNumbers()
{
    int x = 10;
    while( x --> 0 ) // To better understand, the statement could be as follows:while( (x--) > 0 )
    {
      printf("%d ", x);
    }
}

void sortedArrayVSUsorted()
{
    // Generate data
    const unsigned arraySize = 32768;
    int data[arraySize];

    for (unsigned c = 0; c < arraySize; ++c)
        data[c] = std::rand() % 256;

    // !!! With this, the next loop runs faster
    std::sort(data, data + arraySize);

    // Test
    clock_t start = clock();
    long long sum = 0;

    for (unsigned i = 0; i < 100000; ++i)
    {
        // Primary loop
        for (unsigned c = 0; c < arraySize; ++c)
        {
            if (data[c] >= 128) //the culprit is this if-statement
                sum += data[c];
            //int t = (data[c] - 128) >> 31;
            //sum += ~t & data[c];
            //sum += data[c] >=128 ? data[c] : 0;
        }
    }

    double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    std::cout << elapsedTime << std::endl;
    std::cout << "sum = " << sum << std::endl;
}

void oneLoopVSTwoLoops()
{
    const int n = 100000;
//#define ALLOCATE_SEPERATE
//#define ONE_LOOP


#ifdef ALLOCATE_SEPERATE
    double *a1 = (double*)malloc(n * sizeof(double));
    double *b1 = (double*)malloc(n * sizeof(double));
    double *c1 = (double*)malloc(n * sizeof(double));
    double *d1 = (double*)malloc(n * sizeof(double));
#else
    double *a1 = (double*)malloc(n * sizeof(double) * 4);
    double *b1 = a1 + n;
    double *c1 = b1 + n;
    double *d1 = c1 + n;
#endif

    //  Zero the data to prevent any chance of denormals.
    memset(a1,0,n * sizeof(double));
    memset(b1,0,n * sizeof(double));
    memset(c1,0,n * sizeof(double));
    memset(d1,0,n * sizeof(double));

    //  Print the addresses
    std::cout << a1 << std::endl;
    std::cout << b1 << std::endl;
    std::cout << c1 << std::endl;
    std::cout << d1 << std::endl;

    clock_t start = clock();

    int c = 0;
    while (c++ < 10000){

#ifdef ONE_LOOP
        for(int j=0;j<n;j++){
            a1[j] += b1[j];
            c1[j] += d1[j];
        }
#else
        for(int j=0;j<n;j++){
            a1[j] += b1[j];
        }
        for(int j=0;j<n;j++){
            c1[j] += d1[j];
        }
#endif

    }

    clock_t end = clock();
    std::cout << "seconds = " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
}

void denormalFloatVSNormalFloat()
{
#define FLOATING
    //if we flush denormals to zero by adding this to the start of the code:
    //Then the version with 0 is no longer 10x slower and actually becomes faster.
    //_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
    clock_t start = clock();

    const float x[16]={1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6};
    const float z[16]={1.123,1.234,1.345,156.467,1.578,1.689,1.790,1.812,1.923,2.034,2.145,2.256,2.367,2.478,2.589,2.690};
    float y[16];
    for(int i=0;i<16;i++)
    {
        y[i]=x[i];
    }
    for(int j=0;j<9000000;j++)
    {
        for(int i=0;i<16;i++)
        {
            y[i]*=x[i];
            y[i]/=z[i];
#ifdef FLOATING
            y[i]=y[i]+0.1f;
            y[i]=y[i]-0.1f;
#else
            y[i]=y[i]+0;
            y[i]=y[i]-0;
#endif

            if (j > 10000)
                std::cout << y[i] << "  ";
        }
        if (j > 10000)
            std::cout << std::endl;
    }

    clock_t end = clock();
    std::cout << "seconds = " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
}

StringVector& splitString(const std::string &s, char delim, StringVector &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

void splitStringWithoutSTL(const std::string &s, const char delim, StringVector &elems)
{
	std::string temp = s;
	size_t end;
	while ((end = temp.find(delim)) != std::string::npos)
	{
		elems.push_back(temp.substr(0, end));
		temp = temp.substr(end + 1);
	}

	elems.push_back(temp);
}

std::string startTrim(std::string& s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

std::string endTrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

size_t highestBitPosition(unsigned int a)
{
    size_t bits=0;
    while (a!=0) {
        ++bits;
        a>>=1;
    };
    return bits;
}

bool addSafe(unsigned int a, unsigned int b)
{
    size_t a_bits=highestBitPosition(a);
    size_t b_bits=highestBitPosition(b);
    return (a_bits<32 && b_bits<32);
}

bool multiplySafe(unsigned int a, unsigned int b)
{
    size_t a_bits=highestBitPosition(a);
    size_t b_bits=highestBitPosition(b);
    return (a_bits+b_bits<=32);
}

bool exponentSafe(unsigned int a, unsigned int b)
{
    size_t a_bits=highestBitPosition(a);
    return (a_bits*b<=32);
}

bool charactersUnique(const char* s)
{
	assert(s != NULL);
	const char* tmp = s;

	char a[256] = {0};
	while (*tmp != '\0')
	{
		if (a[*tmp] != 0)
		{
			return false;
		}
		else
		{
			a[*tmp]++;
			tmp++;
		}
	}

	return true;
}

void reverseCStr(char* s)
{
	assert(s != NULL);
	char* beg = s;
	char* end = s;
	while (*end != '\0') end++;

	end--;

	while (end > beg)
	{
		char tmp = *beg;
		*beg = *end;
		*end = tmp;
		beg++;
		end--;
	}
}

bool anagrams(const char* a, const char* b)
{
	assert(a != NULL && b != NULL);

	if (strlen(a) != strlen(b)) return false;

	char array[256] = { 0 };
	const char* aBeg = a;
	const char* bBeg = b;

	while (*aBeg != '\0')
	{
		array[*aBeg]++;
		aBeg++;
	}

	while (*bBeg != '\0')
	{
		array[*bBeg]--;
		if (array[*bBeg] < 0) return false;
		bBeg++;
	}

	return true;
}

bool anagramsWithSTL(std::string& a, std::string& b) {
    if(a == "" || b == "") 
        return false;

    if(a.length() != b.length())
        return false;

    std::sort(&a[0], &a[0] + a.length());
    std::sort(&b[0], &b[0] + b.length());
}

void bubbleSort(int a[], int n)
{
	assert(a != NULL);
	if (n <= 1) return;

	for (int i = 0; i < n - 1; i++) 	
	{
		for (int j = 0; j < n - i; j++) 
		{
			if (j == n-1) continue;
			if (a[j] < a[j + 1]) 
			{
				int t = a[j]; 
				a[j] = a[j + 1]; 
				a[j + 1] = t;
			}
		}
	}
}

void quickSort(int a[], int left, int right)
{
	assert(a != NULL);

	if (left > right) return;

	int i = left;
	int j = right;

	int flag = a[i];

	while (i < j)
	{
		while (a[j] >= flag && i < j)
		{
			j--;
		}

		while (a[i] <= flag && i < j)
		{
			i++;
		}

		if (i < j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

	a[left] = a[i];
	a[i] = flag;

	quickSort(a, left, i - 1);
	quickSort(a, i+1, right);

}

void* myMemMove(void* dst, const void* src, const int n)
{
	assert(dst != NULL);
	assert(src != NULL);
	assert(n > 0);

	char* dstTemp = (char*)dst;
	char* srcTemp = (char*)src;
	int count = n;

	if (dst <= src || dst >= srcTemp + n)
	{
		while (count > 0)
		{
			*dstTemp++ = *srcTemp++;
			count--;
		}
	}
	else
	{
		dstTemp += n-1;
		srcTemp += n-1;

		while (count > 0)
		{
			*dstTemp-- = *srcTemp--;
			count--;
		}
	}

	return dst;
}

void humpDel(const char* src , int n, char* dst)
{
	assert(src != NULL);
	assert(n > 0);

	char* flags = (char*)malloc(n);
	while (n > 0)
	{
		flags[n] = 0;
		n--;
	}

	int j = 0;

	for (int i = 0; i < n; i += 2)
	{
		if (src[i] == src[i+2] && src[i] != src[i+1])
		{
			flags[i] = 1;
			flags[i + 1] = 1;
			flags[i + 2] = 1;
			j += 3;
		}
	}
}

void removeDuplicates(char* s) 
{
    int len = strlen(s);
    if(len < 2) return;

    int p=0;
    for(int i=0; i<len; i++) {
        if(s[i] != '\0') {
            s[p++] = s[i];
            for(int j=i+1; j<len; j++) {
                if(s[j] == s[i]) {
                    s[j] = '\0';
                }
            }
        }
    }
    s[p] = '\0';
}

void removeDuplicatesWithDataStructure(char* s) {
    int len = strlen(s);
    if(len < 2) return;

    bool a[256];
    memset(a, 0, sizeof(a));
    int p = 0;

    for(int i=0; i<len; i++) {
        if(!a[s[i]]) {
            s[p++] = s[i];
            a[s[i]] = true;
        }
    }
    a[p] = '\0';
}

void replaceSpaces(const std::string& s, std::string& d) {
    StringVector v;
    splitStringWithoutSTL(s, ' ', v);
    for(StringVector::iterator it = v.begin(); it != v.end(); ++it) {
        d.append(*it);
        if( ++it != v.end()) {
            d.append("%20");
            std::cout<<d<<std::endl;
            --it;
        } else { 
            --it;
        }
    }
}
