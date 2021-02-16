#include <stdio.h>
#include <stdlib.h>
#include "ps.h"
#include "get_list.h"

int main(int argc, char *argv[]){
	/* Set Args */
	int ac = set_args(int argc, char *argv[]);
	if(ac == -1)	{
		printf("Invalid Args\n")		
	}	
  get_list();
 
  

	/*@ Matt do we have to check p val first?
	 * if needed just call get args for p var
	 * Then we call get_info from file parser*/
}
