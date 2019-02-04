#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/dir.h>
#include<string.h>
#include<unistd.h>
void sepa(char *pp,char *l)
{
  DIR *fp=NULL,*up=NULL;
  struct dirent *lx=NULL,*kl=NULL;
  struct stat gh,kk;
  int i;
  if((fp=opendir(l))==0) return;
  while((lx=readdir(fp))!=NULL)
  { 
    stat(lx->d_name,&gh);
    char *p=rindex(lx->d_name,'.');
    if(p!=NULL)
    {   char s[100],z[]=".";
        for(i=1;i<strlen(p);i++) s[i-1]=*(p+i);
        s[i-1]='\0';
        up=opendir(pp);
        while((kl=readdir(up))!= NULL)
        {
          if(!(strcmp(s,kl->d_name)))
          {
           i=-1;break;
          }
        }
        if(i!=-1&& !(S_ISDIR(gh.st_mode))) mkdir(s,0777);
        strcat(z,s);
        if(p!=NULL &&(!strcmp(p,z)))
        {
            char df[1000],ghp[1000];
            strcpy(df,l),strcat(df,"/"),strcat(df,lx->d_name);
            strcpy(ghp,pp),strcat(ghp,"/"),strcat(ghp,s),strcat(ghp,"/"),strcat(ghp,lx->d_name);
            rename(df,ghp);  
        }
      }  
  }
  closedir(fp);
}
void main()
{ 
  char path[1000];
  getcwd(path,1000);
  sepa(path,path);
  printf("Completed\n");
}
