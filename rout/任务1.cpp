#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N = 1000;
const int maxn = 16;
int dis[N][N]; //各边距离
int next[N][N];//相邻点 
int jump[N][N];//下一跳 
int las[N];    //相邻点计数器
int nw[N][N];  //临时路由表
int cl[N][N];  //各边权值

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
 int n,m,c;                    //n为节点数，m为边数，(a,b,c)为一条边的两个节点与长度 
 
 char a,b;
 
 memset(next,0,sizeof(next));  //初始化 
 memset(las,0,sizeof(las));
 memset(jump,0,sizeof(jump));
 
 freopen("data1.txt","r",stdin);
 
 cin>>n>>m;
 
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 {if(i!=j)
 dis[i][j]=maxn;               //设最大距离为15 
 else
 dis[i][j]=0;
 jump[i][j]=j;               //初始化下一跳 
 }
 
 for(int i=1;i<=m;i++)       //读入数据，建图 
 {cin>>a>>b>>c;
  add(a-'A',b-'A',c);
  add(b-'A',a-'A',c);}       
   
 while(!convergence)         //迭代判断 
  {
   convergence=1;
   
   memset(nw,0,sizeof(nw));  //初始化新表单 
   
   for(int i=0;i<n;i++)      //DV算法 
    for(int j=0,ja=next[i][j];j<las[i]-1;j++,ja=next[i][j])
     for(int k=0;k<n;k++)
      if(cl[i][ja]+dis[ja][k]<dis[i][k]||jump[i][k]==ja)
	   {if(!nw[i][k]||cl[i][ja]+dis[ja][k]<nw[i][k]||jump[i][k]==ja)
	    {nw[i][k]=cl[i][ja]+dis[ja][k];//生成新表单
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
	 
	 system("pause");        //每次迭代暂停
	  
  }
 fclose(stdin);
 return 0;   
}
