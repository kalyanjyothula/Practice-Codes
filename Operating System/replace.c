#include<stdio.h>
#include<string.h>
#include<sys/file.h>
#include<sys/dir.h>
#include<dirent.h>
#include<unistd.h>
int main()
{ 
  int p=0;
  char fil[1000];
  getcwd(fil,1000);
  DIR *fp=opendir(fil);
  struct dirent *lx=NULL;
  while((lx=readdir(fp))!=NULL)
  {     
    char *o=rindex(lx->d_name,'/');
    if(o!=NULL)
    {  
       int l=strlen(lx->d_name) - strlen(o);
       char fill[1900]; 
       strncpy(fill,lx->d_name,l);
       printf("%s %s\n",fill,lx->d_name);
       //rename(lx->d_name,fill);  
    }  
  }
  if(p==0) printf("-1\n");
  else printf("*** Completed ***\n");
  return 0;
}
