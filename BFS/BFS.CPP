#include <stdio.h>
#include <fstream>
using namespace std;

ifstream fin;

void BFS(int A[][100], int s, int n, int ThuTu[]);
void nhap(int A[][100], int &s, int &n, int ThuTu[]);
void them(int A[], int &n, int x);
void xoa(int A[], int &n);

void main()
{
	int A[100][100];
	int s,n;
	int ThuTu[100];
	nhap(A,s,n,ThuTu);
	BFS(A,s,n,ThuTu);
}
void xoa(int A[], int &n)
{
	for(int i=0;i<n;i++)
		A[i]=A[i+1];
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
	for(i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin >> A[i][j];
}
void BFS(int A[][100], int s, int n, int ThuTu[])
{
	int Q[100],q=0;
	int color[100];
	int p[100];
	for(int i=0; i<n; i++)
		color[ThuTu[i]]=0;
	color[s]=1;
	p[s]=-1;
	them(Q,q,s);
	while ( q!=0 )
	{
		int u=Q[0]-1;
		for(int v=0; v<n; v++)
			if (A[u][ThuTu[v]-1] == 1)
				if(color[ThuTu[v]]==0)
				{
					color[ThuTu[v]]=1;
					p[ThuTu[v]]=u+1;
					them(Q,q,ThuTu[v]);
				}
		xoa(Q,q);
	}
	for( i=1; i<=n; i++)
		printf("%d ",p[i]);
	printf("\n");
}