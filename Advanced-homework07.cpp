/* 計算機概論實務-進階練習作業-作業7 */
/* 製作人：郭柏鋒 */
/* 完成時間：2019/04/13 24:00 */
//1.用字串指標陣列保存使用者輸入的字串的所有尾碼字串。
//2.將尾碼字串集合進行排序。
//3.比較相鄰字串的公共子串長度，找到長度最大值，保存相應字串即為所求。
//範例1：cabcabca 答案：cabca
//範例2：cabefabc 答案：ab
#include <stdio.h>  //函示庫 
#include <stdlib.h> //函示庫 
#include <string.h> //函示庫 
#include <iostream> //函示庫 
using namespace std;
#define MAXCHAR 100 //最長處理100個字元
char c[MAXCHAR];//字元陣列c保存使用者輸入的字串
char *a[MAXCHAR];//字串指標陣列a保存使用者輸入的字串的所有尾碼字串
 
//求出兩個字串的公共子串長度
int comlen( char *p, char *q )
{
	int i = 0;
	while( *p && (*p++ == *q++))
	{
		i++;     //++i;
	}
 
	return i;
}
 
//字串排序規則
int pstrcmp( const void *p1, const void *p2 )
{
	return strcmp( *(char* const *)p1, *(char* const*)p2 );
}
 
int main(void)
{
	char ch;
	int n = 0;
	int i;
	int temp;
	int  maxlen=0;
	int maxi=0;
 
	printf("請輸入一個字串：");
	while ((ch=getchar()) != '\n')
	{
		//給陣列賦初值
		a[n] = &c[n];
		c[n++] = ch;
	}
 
	c[n] = '\0';
	qsort (a, n, sizeof(char*), pstrcmp );//將尾碼字串集合進行排序
 
	for (i=0; i<n-1; ++i)
	{
		temp = comlen(a[i], a[i+1]);
		if( temp > maxlen )
		{
			maxlen = temp;
			maxi = i;
		}
	}
   printf("此字串中最長相同部分："); 
	for (int i = 0; i < maxlen; i ++)
	{
		cout<<a[maxi][i]; //顯示 
	}
	cout<<endl;
	system("PAUSE");//暫停 
	return 0;//回傳值 0 
}

