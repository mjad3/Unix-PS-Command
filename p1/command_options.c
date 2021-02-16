#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



/* This module processes the command line arguments
 * setting state variables to record what options specify
 *
 * Variables we have to parse -> 
 * -s display single char state info about the process
 * -U display the amount of tume user consumed by this process
 * -S display the amount of system time consumed by this process
 * -v display the amount of virtual memory being used by this program
 * -c display the command-line that started this program
 */

static int s;
static int U;
static int S;
static int v;
static int c;


int ret_arg(char v)	{
	switch(v)	{
		case 's':
			return s;
		case 'U':
			return U;
		case 'S':
			return S;
		case 'v':
			return v;
		case 'c':
			return c;
		default:
			return -1;
		}

	return -1;
}

int main(int argc, char *argv[])	{
	int opt;

	while((opt = getopt(argc, argv, "sUSvc")) != -1)	{
		switch(opt)	{
			case 's':
				s = 1;
				break;
			case 'U':
				U = 1;
				break;
			case 'S':
				S = 1;
				break;
			case 'v':
				v = 1;
				break;
			case 'c':
				c = 1;
				break;
			default:
				printf("This should probably be an error\n");
				return -1;
			}	
	}

	return 0;
}

