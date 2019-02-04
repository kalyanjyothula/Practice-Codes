#include<stdio.h>
int main()
{
  int n,i,z=0,m;
  scanf("%d",&n);
  int rank[n];
  scanf("%d",&rank[0]);
  for(i=1;i<n;i++)
  {
    int y;
    scanf("%d",&y);
    if(rank[z]!=y) rank[++z]=y;
  }
  scanf("%d",&m);
  int alice[m];
  for(i=0;i<m;i++)  scanf("%d",&alice[i]);
  //binary search
  for(i=0;i<m;i++)
  {
    int f=0,l=z,index=0;
    int mid=(f+l)/2;
    while(f<=l)
    {
      
      if(rank[mid]> alice[i])
      {
       f=mid+1;
       index=f;
       }
      else if(rank[mid]==alice[i])
      {
       printf("%d\n",mid+1);
       break;
      }
      else 
      {
        l=mid-1;
        index=l;
      }
      mid=(f+l)/2; 
    }
    if(f>l)
    {
      //printf("%d %d index\n",rank[index],index);
      if(index>=0 && index<=z)
      {
        if(rank[index]>alice[i]) printf("%d\n",index+2);
        else printf("%d\n",index+1);
      }
      else if(index<0) printf("%d\n",index+2);
      else printf("%d\n",index+1);
    }
  }
}
