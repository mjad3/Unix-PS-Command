#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h> 
get_info() 
  
  
void get_info(int pid, int s, int U, int S, int v, int c){
  
  char final[100]; //return string
  
  char id[20]; //holder for new string
  sprintf(id, "%d", pid);
  strcat(final, id);
  strcat(final, ": ");
  char a[100] = "/proc/";
  char b[] = "/stat";
  strcat(a, id);
  strcat(a, b);    
    
  FILE *fp = fopen(a,"r");
  if (fp == NULL) printf("error");
  char n[100];
  int count = 0;
  
  while(fscanf(fp, "%s", n) != EOF){
    count++;
    switch(count){
    case 3:
      if(s == 1){
        strcat(final, n);
        strcat(final, " ");
        }
      break;
    case 14:
      if(U == 1){
        strcat(final, "utime=");        
        strcat(final, n);
        strcat(final, " ");
      }
      break;
    case 15:
      if(S == 1){
        strcat(final, "stime=");        
        strcat(final, n);
        strcat(final, " ");
      }
      break;
    }
  
    
  }
  if(v == 1){
    char d[] = "m"; //to turn stat to statm    
    strcat(a, d); //adds "m" to end of filepath   
    FILE *dp = fopen(a,"r"); //open statm
    if (dp == NULL) printf("error");    
    fscanf(dp, "%s", n);    
    strcat(final, "Size: ");
    strcat(final, n);
    strcat(final, " ");
  }
  if(c == 1){
    char e[100] = "/proc/";
    char f[] = "/cmdline";
    strcat(e, id);
    strcat(e, f);    
    FILE *ep = fopen(e,"r");
    if (ep == NULL) printf("error");    
    fscanf(ep, "%s", n);    
    strcat(final, "COMMAND: ");
    strcat(final, n);
  }
  strcat(final, "\n");
  printf("%s", final);
  
}