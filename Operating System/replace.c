#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
    if(!strcmp(lx->d_name,".") || !strcmp(lx->d_name,"..")) continue;
    char *o=rindex(lx->d_name,'/');    // symbol u want to remove {ex . or \} from filename
    if(o!=NULL)
    {  p=1;
       int l=strlen(lx->d_name) - strlen(o);
       char *fill;        
       strncpy(fill,lx->d_name,l);
       //printf("%s  -- %s\n",fill,lx->d_name);
       rename(lx->d_name,fill);  
       //*fill='\0';
    }  
  }
  if(p==0) printf("-1\n");
  else printf("*** Completed ***\n");
  return 0;
}
