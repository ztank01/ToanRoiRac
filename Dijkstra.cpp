#include <stdio.h>
#include <fstream>
using namespace std;

ifstream fin;

void nhap(int A[][100], int &n, int &s);
void Dijkstra(int A[][100], int n, int s);
bool KhacRong(int T[], int n);
int MinD(int T[], int d[], int n);

void main()
{
	int A[100][100],n,s;
	nhap(A,n,s);
	Dijkstra(A,n,s);
}
void nhap(int A[][100], int &n, int &s) // nhap ma tran W, dinh bat dau s va so dinh n
{
	fin.open("input.txt");
	fin >> s >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin >> A[i][j];
}
void Dijkstra(int A[][100], int n, int s)
{
	int d[100],p[100],T[100];// i=0
	for(int i=0; i<n; i++)
		d[i]=10000;	
	d[s]=0;
	p[s]=-1;
	for(i=0; i<n; i++)
		T[i]=1;
	while ( KhacRong(T,n) )//i=1
	{
		int u=MinD(T,d,n);
		T[u]=0;
		for(int i=0; i<n; i++)
			if ( T[i]==1 && A[u][i]!=10000 && A[u][i]!=0 )// v thuoc T ke voi u
				if( d[i] > d[u]+A[u][i] )
				{
					d[i]=d[u]+A[u][i];
						p[i]=u;
				}
	}
	for( i=0; i<n; i++)
		printf("%d ",d[i]);
	printf("\n");
	for( i=0; i<n; i++)
		printf("%d ",p[i]);
	printf("\n");
}
bool KhacRong(int T[], int n)// khac rong khi co it nhat 1 ptu =1
{
	for(int i=0; i<n; i++)
		if ( T[i]==1 )
			return true;
	return false;
}
int MinD(int T[], int d[], int n)
{
	int min=10000;
	int p;
	for(int i=0; i<n; i++)
		if( min > d[i] && T[i]==1 )//tim min d thuoc T
		{
			min=d[i];
			p=i;
		}
	return p;
}