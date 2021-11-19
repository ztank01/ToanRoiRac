#include <stdio.h>
#include <fstream>
using namespace std;

ifstream fin;

void nhap(int A[][100], int &n, int &s);
void BellmanFord(int A[][100], int s, int n);
void xuat(int A[], int n);

void main()
{
	int A[100][100],n,s;
	nhap(A,n,s);
	BellmanFord(A,s,n);
}
void nhap(int A[][100], int &n, int &s)
{
	fin.open("input.txt");
	fin >> s >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin >> A[i][j];
}
void BellmanFord(int A[][100], int s, int n)
{
	int d[100],p[100];
	for(int v=0; v<n; v++)
		d[v]=10000;
	d[s]=0;
	p[s]=-1;
	for(int i=1; i<n; i++)
	{
		for(int u=0; u<n; u++)
			for(int v=0; v<n; v++)
				if( A[u][v]!=10000 && A[u][v]!=0 )
					if (d[v] > d[u]+A[u][v])
					{
						d[v]=d[u]+A[u][v];
						p[v]=u;
					}
	}
	for(int u=0; u<n; u++)
			for(int v=0; v<n; v++)
				if( A[u][v]!=10000 && A[u][v]!=0 )
					if( d[v] > d[u]+A[u][v] )
					{
						printf("Co Chu Trinh Am\n");
						exit(0);
					}
	xuat(d,n);
	xuat(p,n);
}
void xuat(int A[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
