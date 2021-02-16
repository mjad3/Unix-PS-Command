#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h> 
#include "get_info.h"
get_list()



void get_list(){
  //if(p) //get pid from commandline and call get_info(pid)
  int uid = getuid();
  char u[10];
  sprintf(u, "%d", uid); //convert uid to string
  char ch_ar[3000][50]; //array to store all items in /proc/
  struct dirent *dt;   
  DIR *dr = opendir("/proc/"); 
  
  if (dr == NULL){ 
    printf("Could not open current directory" ); 
    return 0; 
  } 
     
  int count = 0;
  while ((dt = readdir(dr)) != NULL){ 
    char *item = dt->d_name;
    if(atoi(item)){   //check if item is a process number
      strcpy(ch_ar[count], dt->d_name);  
      count++; 
    }           
                    
  }
  int z = 300;
  int x = 8;
  char final[z][x]; //return array for proc list
  int d = 0; //placeholder for pos in final array
  for(int i = 0; i < count; i++){
      //printf("%s\n", ch_ar[i]);
          
    char e[100] = "/proc/";
    char f[] = "/status";
    strcat(e, ch_ar[i]);  //add "/proc/" to pid
    strcat(e, f);         //add those to "/status"
    FILE *ep = fopen(e,"r");
    if (ep == NULL) printf("error");
    char line[256];
    int c = 1; //count for finding 9th line
      
    while(fgets(line, sizeof(line), ep)){
      if(c == 9 && strstr(line, u)){ //if 9th line in status and contains uid
        strcpy(final[d], ch_ar[i]);  //add that pid to final array
        d++;
      }
        
      c++;
    }
      
  }
    //return final; //not sure how to return this yet
    //for(int i = 0; i < 20; i++){ //prints array of pids to return
      //get_info(final[i], s, U, S, v, c);
    //}
  closedir(dr);     
 
}

