#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include<sys/stat.h>
#include <stdio.h>
#include<string.h>
#include<unistd.h>
void printing(char *die,char*p1)
{
  int i,k=0;
  for(i=0;i<strlen(die);i++)
  {
    if(*(p1+i) != *(die+i)) k=1;
  }
  if(k==0) printf("%s\n",p1);  
}

void recount(char *l, char die[])
{
    DIR *fp=NULL;
    struct dirent *lx=NULL;
    struct stat ff;
    if ((fp = opendir(l))==0) return;
    while ((lx=readdir(fp)) != NULL) 
    {
        stat(lx->d_name,&ff);
        if (S_ISDIR(ff.st_mode)) 
        {
            if ((strcmp(lx->d_name,".") == 0 )|| (strcmp(lx->d_name,"..") == 0)) continue;
            char path[1000];    
            strcpy(path,l),strcat(path,"/"),strcat(path,lx->d_name);
            if(opendir(lx->d_name)!=0) 
              printf("Directory : [ %s ]\n",lx->d_name);
            else  
              printing(die,lx->d_name);
            recount(path,die);
            printf("----\n");
        } 
        else printing(die,lx->d_name);
    } 
    closedir(fp);
}

void main(int argc,char *argv[]) 
{   
    char ff[1000];
    getcwd(ff,1000);
    if(argc>2) printf("\nInValid Input\n");
    else recount(ff,argv[1]);
}

