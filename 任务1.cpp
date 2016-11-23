#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N = 1000;
const int maxn = 16;
int dis[N][N]; //���߾���
int next[N][N];//���ڵ� 
int jump[N][N];//��һ�� 
int las[N];    //���ڵ������
int nw[N][N];  //��ʱ·�ɱ�
int cl[N][N];  //����Ȩֵ

bool convergence = 0;

void add(int a,int b,int c)
{next[a][las[a]] = b;
 next[b][las[b]] = a;
 dis[a][b] = c;
 dis[b][a] = c;
 cl[b][a] = c;
 cl[a][b] = c;
 las[a]++;
 las[b]++;} 

int main()
{
 int n,m,c;                    //nΪ�ڵ�����mΪ������(a,b,c)Ϊһ���ߵ������ڵ��볤�� 
 
 char a,b;
 
 memset(next,0,sizeof(next));  //��ʼ�� 
 memset(las,0,sizeof(las));
 memset(jump,0,sizeof(jump));
 
 freopen("data1.txt","r",stdin);
 
 cin>>n>>m;
 
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 {if(i!=j)
 dis[i][j]=maxn;               //��������Ϊ15 
 else
 dis[i][j]=0;
 jump[i][j]=j;               //��ʼ����һ�� 
 }
 
 for(int i=1;i<=m;i++)       //�������ݣ���ͼ 
 {cin>>a>>b>>c;
  add(a-'A',b-'A',c);
  add(b-'A',a-'A',c);}       
   
 while(!convergence)         //�����ж� 
  {
   convergence=1;
   
   memset(nw,0,sizeof(nw));  //��ʼ���±� 
   
   for(int i=0;i<n;i++)      //DV�㷨 
    for(int j=0,ja=next[i][j];j<las[i]-1;j++,ja=next[i][j])
     for(int k=0;k<n;k++)
      if(cl[i][ja]+dis[ja][k]<dis[i][k]||jump[i][k]==ja)
	   {if(!nw[i][k]||cl[i][ja]+dis[ja][k]<nw[i][k]||jump[i][k]==ja)
	    {nw[i][k]=cl[i][ja]+dis[ja][k];//�����±�
	    jump[i][k]=ja;
		} 
	    if(cl[i][ja]+dis[ja][k]!=dis[k][i])
	    {
		convergence=0;
		}}
	    
   for(int i=0;i<n;i++)
    {cout<<char(i+'A')<<":"<<endl;
	 for(int j=0;j<n;j++)
	 {cout<<char(j+'A')<<" "<<char(jump[i][j]+'A')<<" ";
	  if(nw[i][j])
	  {cout<<nw[i][j]<<endl;
	   dis[i][j]=nw[i][j];
	  }
	  else
	  cout<<dis[i][j]<<endl;
	 }
	}
	 
	 system("pause");        //ÿ�ε�����ͣ
	  
  }
 fclose(stdin);
 return 0;   
}
