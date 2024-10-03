/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "RPC_System.h"

ordered list;

void *append_1_svc(ordered *argp, struct svc_req *rqstp)
{
	static char * result;
	int i=0, j=0;
	list.ordered_len += 8;

	if (list.ordered_len == 8) {
		list.ordered_val = malloc(((argp->ordered_len * sizeof(int)) + 1));
	}
	else {
		list.ordered_val = realloc(list.ordered_val, ((list.ordered_len * sizeof(int)) + 1));
	}
	
	//find the end of list
	while(*(list.ordered_val+i)!='\0'){
		i++;
	}

	//append s to d
	while((argp->ordered_len + j)!='\0'){
		*(list.ordered_val+i) = *(argp->ordered_val+j);
		i++;
		j++;
	}
	*(list.ordered_val+i)='\0';

	return (void *) &result;
}

int * query_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("query recieved for index %d", *argp);

	

	return &result;
}

void * remove_1_svc(int *argp, struct svc_req *rqstp)
{
	static char * result;

	printf("remove recieved for index %d", *argp);
	list.ordered_len -= 1;

	return (void *) &result;
}
