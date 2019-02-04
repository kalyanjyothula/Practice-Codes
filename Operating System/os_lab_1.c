#include<stdio.h>
#include <sys/file.h>
//#include<sys/stat.h>
//#include<sys/types.h>
//#include<sys/dir.h>
//#include<dirent.h>
#include<unistd.h>
#include<string.h>
int read_skip(int fp,char *buf,int bs,int n,int ss)
{
  if(fp==-1) return -1;
  else
  { 
    int i=0,j=bs,p=0;
    char l;
    while((i< n*(bs+ss))&& read(fp,&l,1))
    { 
      if(i<j)
      {   
          *(buf+p)=l;
           p++;i++;
      }
      else
      {
        i=i+ss;
        j=i+bs;
        lseek(fp,ss-1,1);
      }    
    }
    if(i!=n*(bs+ss)) return -1;
    else return p;
    }
}

void main(int argc,char * argv[])
{ 
  if(argc>4)
  {
    char p[]={"INVALID INPUT\n"};
    write(1,&p,15);
  }  
  else
  { 
    int bs,n,ss,p;
    bs=(int)argv[1][0]-48,n=(int)argv[2][0]-48,ss=(int)argv[3][0]-48;
    char buf[n*bs],c;
    write(1,"Enter the Size Of File Name::",29);
    read(0,&c,1);
    p=(int)c-48;
    char file[p];
    read(0,&c,1);
    write(1,"File Name ::",12);
    read(0,&file,p);
    bs=read_skip(open(file,O_RDWR,7),buf,bs,n,ss);
    if(bs!=-1)
    { 
      *(buf+bs)='\0';
      p=strlen(buf);
      write(1,&buf,p+1);
      n=0;
      file[0]='\0';
      while(p>0)
      {
        bs=p%10;
        file[n]=(char)bs+48;
        n++;
        p=p/10; 
      }
      file[n]='\0';
      c='\n';
      write(1,&c,1);
      while(n>0 && write(1,&file[n-1],1)) n--;
      write(1,&c,1);
    }
    else
    { 
      char pp[]={"UNSUCCESFUL\n"};
      write(1,&pp,12);
    } 
  }   
}
