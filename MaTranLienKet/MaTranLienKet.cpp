#include <stdio.h>
#include <fstream>

using namespace std;

ifstream fin;

void nhap(int A[][100], int &m, int &n);
int DemSongSong(int A[][100], int m, int n);
bool KiemTraSongSong(int A[][100], int m, int i, int j);
int DemVong(int A[][100], int m, int n);
bool KiemTraVong(int A[][100], int m, int j);
int DemDinhTreo(int A[][100], int m, int n);
bool KiemTraDinhTreo(int A[][100], int n, int i);
int DemDinhCoLap(int A[][100], int m, int n);
bool KiemTraCoLap(int A[][100], int n, int i);

void main()
{
	int A[100][100];
	int m,n;
	nhap(A,m,n);
	int songsong=DemSongSong(A,m,n);
	int vong=DemVong(A,m,n);
	int dinhtreo=DemDinhTreo(A,m,n);
	int dinhcolap=DemDinhCoLap(A,m,n);
	printf("So Canh Song Song: %d\n",songsong);
	printf("So Vong: %d\n",vong);
	printf("So Dinh Treo: %d\n",dinhtreo);
	printf("So Dinh Co Lap: %d\n",dinhcolap);

}
void nhap(int A[][100], int &m, int &n)
{
	fin.open("input.txt");
	fin >> m >> n;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			fin >> A[i][j];
}
int DemSongSong(int A[][100], int m, int n)
{
	int c=0;
	for(int i=0; i<m; i++)
		for(int j=i+1; j<n; j++)
			if( KiemTraSongSong(A,m,i,j))
				c++;
	return c;
}
bool KiemTraSongSong(int A[][100], int m, int i, int j)
{
	for(int x=0; x<m; x++)
		if (A[x][i] != A[x][j] )
			return false;
		return true;
}
int DemVong(int A[][100],int m, int n)
{
	int c=0;
	for(int j=0; j<n; j++)
		if (KiemTraVong(A,m,j))
			c++;
	return c;
}
bool KiemTraVong(int A[][100], int m, int j)
{
	int c=0;
	for(int i=0; i<m; i++)
		if (A[i][j]==1)
			c++;
		if (c==1)
			return true;
		return false;
}
int DemDinhTreo(int A[][100], int m, int n)
{
	int c=0;
	for(int i=0; i<m; i++)
		if (KiemTraDinhTreo(A,n,i))
			c++;
	return c;
}
bool KiemTraDinhTreo(int A[][100], int n, int i)
{
	int c=0;
	for(int j=0; j<n; j++)
		if (A[i][j]==1)
			c++;
		if (c==1)
			return true;
		return false;
}
int DemDinhCoLap(int A[][100], int m, int n)
{
	int c=0;
	for(int i=0; i<m; i++)
		if (KiemTraCoLap(A,n,i))
			c++;
	return c;
}
bool KiemTraCoLap(int A[][100], int n, int i)
{
	for(int j=0; j<n; j++)
		if (A[i][j]==1)
			return false;
	return true;
}