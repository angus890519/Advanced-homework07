/* �p������׹��-�i���m�ߧ@�~-�@�~7 */
/* �s�@�H�G���f�W */
/* �����ɶ��G2019/04/13 24:00 */
//1.�Φr����а}�C�O�s�ϥΪ̿�J���r�ꪺ�Ҧ����X�r��C
//2.�N���X�r�궰�X�i��ƧǡC
//3.����۾F�r�ꪺ���@�l����סA�����׳̤j�ȡA�O�s�����r��Y���ҨD�C
//�d��1�Gcabcabca ���סGcabca
//�d��2�Gcabefabc ���סGab
#include <stdio.h>  //��ܮw 
#include <stdlib.h> //��ܮw 
#include <string.h> //��ܮw 
#include <iostream> //��ܮw 
using namespace std;
#define MAXCHAR 100 //�̪��B�z100�Ӧr��
char c[MAXCHAR];//�r���}�Cc�O�s�ϥΪ̿�J���r��
char *a[MAXCHAR];//�r����а}�Ca�O�s�ϥΪ̿�J���r�ꪺ�Ҧ����X�r��
 
//�D�X��Ӧr�ꪺ���@�l�����
int comlen( char *p, char *q )
{
	int i = 0;
	while( *p && (*p++ == *q++))
	{
		i++;     //++i;
	}
 
	return i;
}
 
//�r��ƧǳW�h
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
 
	printf("�п�J�@�Ӧr��G");
	while ((ch=getchar()) != '\n')
	{
		//���}�C����
		a[n] = &c[n];
		c[n++] = ch;
	}
 
	c[n] = '\0';
	qsort (a, n, sizeof(char*), pstrcmp );//�N���X�r�궰�X�i��Ƨ�
 
	for (i=0; i<n-1; ++i)
	{
		temp = comlen(a[i], a[i+1]);
		if( temp > maxlen )
		{
			maxlen = temp;
			maxi = i;
		}
	}
   printf("���r�ꤤ�̪��ۦP�����G"); 
	for (int i = 0; i < maxlen; i ++)
	{
		cout<<a[maxi][i]; //��� 
	}
	cout<<endl;
	system("PAUSE");//�Ȱ� 
	return 0;//�^�ǭ� 0 
}

