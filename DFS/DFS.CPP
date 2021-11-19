#include <stdio.h>
#include <fstream>
using namespace std;

ifstream fin;

void xoa(int A[], int &n);
void them(int A[], int &n, int x);
void nhap(int A[][100], int &s, int &n, int ThuTu[]);
void DFS(int A[][100], int s, int n, int ThuTu[]);

void main()
{
	int A[100][100],n,s;
	int ThuTu[100];
	nhap(A,s,n,ThuTu);
	DFS(A,s,n,ThuTu);
}
void xoa(int A[], int &n)
{
	n--;
}
void them(int A[], int &n, int x)
{
	A[n]=x;
	n++;
}
void nhap(int A[][100], int &s, int &n, int ThuTu[])
{
	fin.open("input.txt");
	fin >> s >> n;
	for(int i=0; i<n; i++)
		fin >> ThuTu[i];
	for( i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin >> A[i][j];
}
void DFS(int A[][100], int s, int n, int ThuTu[])
{
	int St[100],k=0,D[100],p[100];
	for(int i=0 ;i<n; i++)
		D[ThuTu[i]]=0;
	D[s]=1;
	p[s]=-1;
	them(St,k,0);
	int u=s;
	while ( u!=0 )
	{
		for(int i=0; i<n; i++)
			if ( A[u-1][ThuTu[i]-1]==1 && D[ThuTu[i]]==0 )
			{
				D[ThuTu[i]]=1;
				p[ThuTu[i]]=u;
				them(St,k,u);
				u=ThuTu[i];
			}
		u=St[k-1];
		xoa(St,k);
	}
	for( i=1; i<=n; i++)
		printf("%d ",p[i]);
	printf("\n");
}
