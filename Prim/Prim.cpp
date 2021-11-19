#include <stdio.h>
#include <fstream>
using namespace std;

ifstream fin;

void nhap(int A[][100], int &n, int &r);
void Prim(int A[][100], int n, int r);
bool KhacRong(int S[], int n);
int TimKeyMin( int S[], int n, int key[] );

void main()
{
	int A[100][100];
	int n,r;
	nhap(A,n,r);
	Prim(A,n,r);
}
void nhap(int A[][100], int &n, int &r)
{
	fin.open("input.txt");
	fin >> r >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin >> A[i][j];
}
void Prim(int A[][100], int n, int r)
{
	int S[100],key[100],p[100];
	for(int i=0; i<n; i++)
	{
		S[i]=1;
		key[i]=10000;
	}
	key[r]=0;
	p[r]=-1;
	while ( KhacRong(S,n) )
	{
		int u=TimKeyMin(S,n,key);
		S[u]=0;
		for(int j=0; j<n; j++)
			if ( S[j]==1 && A[u][j]!=10000 && A[u][j]!=0)
				if ( A[u][j] < key[j] )
				{
					p[j]=u;
					key[j]=A[u][j];
				}
	}
	for(i=0; i<n; i++)
		printf("%d ",p[i]);
}
bool KhacRong(int S[], int n)
{
	for(int i=0; i<n; i++)
		if ( S[i]==1 )
			return true;
	return false;
}
int TimKeyMin( int S[], int n, int key[] )
{
	int Min=10000;
	int p;
	for(int i=0; i<n; i++)
		if ( S[i]==1 && key[i]<Min )
		{
			p=i;
			Min=key[i];
		}
	return p;
}