#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

ifstream fin;

void nhap(int D[][100], int &n);
void Kruskal(int D[][100], int n);
int ChuaTrong(char S[][100], int x, int n);

void main()
{
	int D[100][100],n;
	nhap(D,n);
	Kruskal(D,n);
}
void nhap(int D[][100], int &n)
{
	fin.open("input.txt");
	fin >> n ;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin >> D[i][j];
}
void Kruskal(int D[][100], int n)
{
	int A[100],k=0;
	char S[100][100];
	for(int i=0; i<n; i++)
	{
		S[i][0]='0'+i;
		S[i][1]=NULL;
	}
	int V[100],X[100],Y[100];
	for(int c=0; c<n; c++)
	{
		V[c]=D[0][1];X[c]=0; Y[c]=1;
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				if ( D[i][j]!=10000 && D[i][j]!=0 )
					if ( V[c] > D[i][j] )
					{
						V[c]=D[i][j];
						X[c]=i;
						Y[c]=j;
					}
		D[X[c]][Y[c]]=10000;
	}
	for(i=0; i<n; i++)
	{
		int a=ChuaTrong(S,X[i],n); 
		int b=ChuaTrong(S,Y[i],n);
		if ( a!=b )
		{
			if ( a>b )
				strcat(S[b],S[a]);
			else
				strcat(S[a],S[b]);
			A[k++]=X[i];
			A[k++]=Y[i];
		}
	}
	for(i=0; i<k; i++)
		printf("%d ",A[i]);
	printf("\n");
}
int ChuaTrong(char S[][100], int x, int n)
{
	for(int i=0; i<n; i++)
	{
		int j=0;
		while ( S[i][j]!= NULL)
		{
			if( ('0'+ x)== S[i][j]  )
				return i;
			else
				j++;
		}
	}
}
