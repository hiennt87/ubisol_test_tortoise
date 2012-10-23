#include<iostream.h>
#include "stdio.h"
#include "windows.h"
#include <ctime>

int KhoangCachNgay(int, int, int);

int main()
{

	KhoangCachNgay(30,12,2013);
	cout<<"finish"<<endl;
	cout<<"2 thang them moi "<<endl;
	return 0;
}

int KhoangCachNgay(int dd, int mm, int yy)
{
	time_t t;
	time(&t);
	char *str = ctime(&t);
	char stry[4] = "";
	char strm[3] = "";
	char strd[2] = "";	

	int index = 0;
	int len = strlen(str) - 1;

	// lay nam hien tai
	for (int i= len - 4; i < len; i++)
	{
		if (index == 4)
			break;
		stry[index] += str[i];
		index ++;
	}
	int cy = atoi(stry);

	// lay thang hien tai
	index = 0;
	for (i= 4; i < 7; i++)
	{
		strm[index] += str[i];
		index ++;
	}
	
	int cm = 1;
	if (strstr(strm,"Oct") != NULL)
	{
		cm = 10;
	}
	else if (strstr(strm,"Nov") != NULL)
	{
		cm = 11;
	}
	else if (strstr(strm,"Dec") != NULL)
	{
		cm = 12;
	}
	else if (strstr(strm,"Jan") != NULL)
	{
		cm = 1;
	}
	else if (strstr(strm,"Feb") != NULL)
	{
		cm = 2;
	}
	else if (strstr(strm,"Mar") != NULL)
	{
		cm = 3;
	}
	else if (strstr(strm,"Apr") != NULL)
	{
		cm = 4;
	}
	else if (strstr(strm,"May") != NULL)
	{
		cm = 5;
	}
	else if (strstr(strm,"Jun") != NULL)
	{
		cm = 6;
	}
	else if (strstr(strm,"Sep") != NULL)
	{
		cm = 9;
	}
	else if (strstr(strm,"Aug") != NULL)
	{
		cm = 8;
	}
	else
		cm = 7;

	// lay ngay hien tai
	index = 0;
	for (i= 8; i < 10; i++)
	{
		strd[index] += str[i];
		index ++;
	}	
	int cd = atoi(strd);
	
	int songaychotoingaycantinh = 0, songaychotoihientai = 0;
	
	int ThangTrongNam[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
	// tinh so ngay cho toi ngay can tim.
	int sonam1 = yy - 1;
	int a1 = sonam1 * 365 + (sonam1 / 4);		
	mm = mm - 1;

 	if (yy % 4 == 0)
	{		
		ThangTrongNam[1] = 29;
	}
	for (int ii = 0; ii < mm; ii++)
	{
		songaychotoingaycantinh += ThangTrongNam[ii];
	}
	songaychotoingaycantinh = (a1 + songaychotoingaycantinh + dd) ;

	// tinh so ngay cho toi ngay hien tai
	int sonam = cy - 1;
	int a = sonam * 365 + (sonam / 4);		
	cm = cm - 1;

	if (cy % 4 == 0)
	{		
		ThangTrongNam[1] = 29;
	}
	for (ii = 0; ii < cm; ii++)
	{
		songaychotoihientai += ThangTrongNam[ii];
	}
	songaychotoihientai = (a + songaychotoihientai + cd) ;

	return songaychotoingaycantinh - songaychotoihientai;
}




