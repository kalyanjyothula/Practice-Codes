#include<stdio.h>
#include<sys/dir.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
void compare(char *l,char hp[])
{ int pp=0;
  DIR * bv=NULL;
  struct dirent *jk=NULL;
  if((bv=opendir(l))==0) return;
  while((jk=readdir(bv))!=NULL)
  {
    if(!(strcmp(hp,jk->d_name)))
    { 
      char *k=rindex(l,'/');
      if(!(strcmp(jk->d_name,".")) || !(strcmp(jk->d_name,".."))) continue;
      printf(" %s in Directory  '%s /'\n",jk->d_name,k);
      printf("Enter 1 to remove '%s' ::",jk->d_name); scanf("%d",&pp);
      if(pp==1)
      {
        remove(jk->d_name);
        pp=0;
      }
    }
  }
}
void main()
{ 
  int y=0;
  
  char pa[100],path[1000];
  printf("Enter Directory Name::");
  scanf("%s",pa);
  char diw[1000];
  getcwd(diw,1000);
  strcpy(path,diw);
  strcat(path,"/"),strcat(path,pa);
  DIR *fp=opendir(diw);
  struct dirent *lx=NULL;
  while((lx=readdir(fp))!=NULL)
  { 
    y=1;
    if(strcmp(lx->d_name,pa))
    {
      compare(path,lx->d_name);
    }  
    
  }
  if(y!=1) printf("NOT EXist\n"); 
}
