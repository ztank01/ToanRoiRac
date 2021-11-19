#include <stdio.h>
#include <fstream>
using namespace std;

ifstream fin;

void nhap(int W[][100], int &n);
void KhoiTaoD(int *&D, int n);
void Dijkstra(int W[][100], int n, int *&D, int *&P);
int MinD(int *D, int *&T, int &k);
void xuat(int *D, int *P, int n);

void main()
{
	int W[100][100],n;
	nhap(W,n);
	int *D=new int[n];
	int *P=new int[n];
	KhoiTaoD(D,n);
	Dijkstra(W,n,D,P);
	xuat(D,P,n);
	delete []D;
	delete []P;
}
void nhap(int W[][100], int &n)
{
	fin.open("input.txt");	
	fin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin >> W[i][j];
}
void KhoiTaoD(int *&D, int n)
{
	for(int i=0; i<n; i++)
		D[i]=10000;
}
void Dijkstra(int W[][100], int n, int *&D, int *&P)
{
	int st;
	scanf("%d",&st);
	D[st]=0;
	P[st]=-1;
	int *T=new int[n];
	for(int i=0; i<n;i++)
		T[i]=i;
	int k=n;
	while ( k != 0 )
	{
		int u=MinD(D,T,k);
		for(i=0; i<n; i++)
			if ( W[u][i] != 10000 )
				if( D[i] > D[u] +W[u][i] )
				{
					D[i]=D[u]+W[u][i];
					P[i]=u;
				}
	}
			
	delete []T;
}
int MinD(int *D, int *&T, int &k)
{
	int min=D[0],u=T[0],flag=0;
	for(int i=1; i<k; i++)
		if( min>D[T[i]] )
		{
			min=D[i];
			u=T[i];
			flag=i;
		}
	for( i=flag; i<k-1; i++)
		T[i]=T[i+1];
	k--;
	return u;
}
void xuat(int *D, int *P, int n)
{
	for(int i=0; i<n; i++)
		printf("%d ",D[i]);
	printf("\n");
	for(i=0; i<n; i++)
		printf("%d ",P[i]);
		printf("\n");
}