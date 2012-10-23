#include<iostream.h>
#include "stdio.h"
#include "windows.h"
#include <ctime>

int KhoangCachNgay(int, int, int);

int main()
{
	/*int		multi_item[326];

	cout<<"size: "<<sizeof(int)<<endl;*/

	//+ pointer
	/*int *a = new int;
	int x = 100, y = 200;
	a = &x;
	cout<<"*a= "<<*a<<" a="<<a<<endl;
	int *b = a;
	cout<<"*a= "<<*a<<" a="<<a<<endl;
	cout<<"*b= "<<*b<<" b="<<b<<endl;
	*b = 600;
	cout<<"*a= "<<*a<<" a="<<a<<endl;
	cout<<"*b= "<<*b<<" b="<<b<<endl;*/
	//-

	//+ File
/*	HANDLE 	gpFile;
	char	fname[70];
	char	fname2[50];
	//char    name[30] = "20111107.IDT";
	char    name[30] = "RGTCUP.TBL";
	char		test[13];

	sprintf(fname, "%s%s", "C:\\", name);
	sprintf(fname2, "%s%s", "D:\\", name);
	gpFile = CreateFile(fname, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
							NULL, OPEN_EXISTING, FILE_FLAG_WRITE_THROUGH | FILE_FLAG_RANDOM_ACCESS, NULL);
	//char bufVer[30] = "nguyen thi hien";
	ULONG	gpSize;

	if (gpFile != INVALID_HANDLE_VALUE)
	{
		//WriteFile( gpFile, bufVer, 30, (unsigned long *)&gpSize, NULL );
		// read file
	/*	int ret = ReadFile(gpFile,test,13,&gpSize,NULL);
		if (ret == 0)
			cout<<"Read file fail."<<endl;
		else
		{
			for (int i=0; i<13; i++)
				//if (strcmp(test[i], ' ') != 0)
					cout<<test[i];
		}
		cout<<endl;*
		// move file
		
		if (!MoveFileEx(fname, fname2, MOVEFILE_REPLACE_EXISTING | MOVEFILE_COPY_ALLOWED))
			cout<<"Move file fail."<<endl;
		
	}*/
	//int ret = CopyFile(fname, fname2, FALSE);
	
/*	char MapObjName[30];
	sprintf(MapObjName, "%s", L"SharedObj");
	char * pBuf1;
	HANDLE  hMapFile = CreateFileMapping(gpFile, NULL, PAGE_READWRITE, 0, BUF_SIZE, MapObjName);
	pBuf1 = (char *)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);

	ZeroMemory(pBuf1 + BUF_SIZE - 1, 1);
	getchar();*/
	//-

	// Chuong trinh tinh thu khi biet ngay thang nam.
	/*int ngay, thang, nam;
	cout<<"ngay:"; cin>>ngay;
	cout<<"thang:"; cin>>thang;
	cout<<"nam:"; cin>>nam;*/
	
	//int ret = TinhThuTheoNgay(ngay, thang, nam);

	// Chuong trinh doi ngay duong ra ngay am.
	/*try
	{
		if ((nam < 1) || (nam > 9999))
			throw "Nam khong lon hon 9999.";
		if ((thang < 1) || (thang > 12))
			throw "Thang khong nho hon 1 hoac lon hon 12";

		if ((nam % 4 == 0) && (thang == 2))
		{
			if ((ngay < 1) || (ngay > 29))
				throw "Ngay khong nho hon 1 hoac lon hon 29";
		}
		else
		{
			if (thang == 2)
			{
				if ((ngay < 1) || (ngay > 28))
					throw "Ngay khong nho hon 1 hoac lon hon 28";
			}
			else if ((thang == 1) || (thang == 3) || (thang == 5) || (thang == 7) || (thang == 8) || (thang == 10) || (thang == 12))
			{
				if ((ngay < 1) || (ngay > 31))
					throw "Ngay khong nho hon 1 hoac lon hon 31";
			}
			else
			{
				if ((ngay < 1) || (ngay > 30))
					throw "Ngay khong nho hon 1 hoac lon hon 30";
			}
		}		
	//	cout<<"Ngay Am lich: "<<convertSolar2Lunar(ngay, thang, nam)<<endl;
		cout<<"Khoang cach:"<<KhoangCachNgay(ngay, thang, nam)<<endl;
	}
	catch(char * str)
	{
		cout<<str<<endl;
	}*/
	KhoangCachNgay(30,12,2013);
	cout<<"finish"<<endl;
	cout<<"1 thang them moi "<<endl;
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




