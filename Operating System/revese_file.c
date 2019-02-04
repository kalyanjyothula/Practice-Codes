#include<stdio.h>
#include<string.h>
#include<sys/file.h>
#include<sys/dir.h>
#include<dirent.h>
#include<unistd.h>
int main()
{ 
  char fil[1000];
  getcwd(fil,1000);
  DIR *fp=opendir(fil);
  struct dirent *lx=NULL;
  while((lx=readdir(fp))!=NULL)
  {  
       int l=strlen(lx->d_name),i=0;
       //printf("%s %d\n",lx->d_name,l);
       char fill[l+4]; 
       memset(fill, '\0', sizeof(fill));
       for(l;l>=0;l--,i++)
       {
        fill[i]=lx->d_name[l-1];
        //printf("%c %d\n",lx->d_name[l-1],l-1);
       }
       fill[i]='\0';
      //printf("%s \n",fill);
      rename(lx->d_name,fill); 
    }
  return 0;
}
