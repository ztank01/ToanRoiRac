#include <stdio.h>
#include <fstream>
using namespace std;

ifstream fin;

void nhap(int A[][100], int &n);
int DemVong(int A[][100], int n);
int DemDinhTreo(int A[][100], int n);
bool KiemTraDinhTreo(int A[][100], int n, int i);
int DemDinhCoLap(int A[][100], int n);
bool KiemTraDinhCoLap(int A[][100], int n, int i);

void main()
{
	int A[100][100];
	int n;
	nhap(A,n);
	int vong=DemVong(A,n);
	int dinhtreo=DemDinhTreo(A,n);
	int dinhcolap=DemDinhCoLap(A,n);
	printf("So Vong: %d\n",vong);
	printf("So Dinh Treo: %d\n",dinhtreo);
	printf("So Dinh Co Lap: %d\n",dinhcolap);
}
void nhap(int A[][100], int &n)
{
	fin.open("input.txt");
	fin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin >> A[i][j];
}
int DemVong(int A[][100], int n)
{
	int c=0;
	for(int i=0; i<n; i++)
		if ( A[i][i]==1 )
			c++;
	return c;
}
int DemDinhTreo(int A[][100], int n)
{
	int c=0;
	for(int i=0; i<n; i++)
		if (KiemTraDinhTreo(A,n,i))
			c++;
	return c;
}
bool KiemTraDinhTreo(int A[][100], int n, int i)
{
	int c=0;
	for(int j=0; j<n; j++)
		if ( A[i][j]==1 )
			c++;
	if ( c==1)
			return true;
	return false;
}
int DemDinhCoLap(int A[][100], int n)
{
	int c=0;
	for(int i=0; i<n; i++)
		if (KiemTraDinhCoLap(A,n,i))
			c++;
	return c;
}
bool KiemTraDinhCoLap(int A[][100], int n, int i)
{
	for(int j=0; j<n; j++)
		if ( A[i][j]==1)
			return false;
	return true;
}