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
    char *o=rindex(lx->d_name,'.');
    if(o!=NULL && strcmp(o,".txt") ==0)
    {  
      if(p==0)
      { fil[0]='\0';
        printf("Enter the File Name:-"),scanf("%s",fil);
        creat(fil,S_IRWXU);
        p=1;
      }
      int fpz=open(fil,O_WRONLY,0);
      lseek(fpz,0,2);     
      int fpp=open(lx->d_name,O_RDONLY,0);
      char w;
      while(read(fpp,&w,1) && write(fpz,&w,1));
      close(fpp);
    }  
  }
  if(p==0) printf("-1\n");
  else printf("*** Completed ***\n");
  return 0;
}
