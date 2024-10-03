/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "RPC_System.h"


int main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	if (argc < 3) {
		printf("Too few arguments");
		exit(1);
	}

	host = argv[1];
	char* type = argv[2];

	CLIENT *clnt;
	void  *result_1;
	ordered  append_1_arg;
	int  *result_2;
	int  query_1_arg;
	void  *result_3;
	int  remove_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, RPC_SYSTEM_PROGRAM, RPC_SYSTEM_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit(1);
	}
#endif	/* DEBUG */

	char req = type[0];

	if (req == 'a' || req == 'A'){
		int num = argc - 3;
		int input[num];
		
		for (int i = 0; i < num; i++) {
			input[i] = atoi(argv[i + 3]);
		}

		// Add elements to new ordered list
		ordered list;
		list.ordered_len = num;
		list.ordered_val = input;

		append_1(&list, clnt);
	}
	else if (req == 'q' || req == 'Q') {
		if (argc < 4) {
			printf("Not enought arguments");
			exit(1);
		}

		int index = atoi(argv[3]);
		printf("Index %d: %d\n", index, *query_1(&index, clnt));
	}
	else if (req == 'r' || req == 'r'){
		if (argc < 4) {
			printf("Not enought arguments");
			exit(1);
		}

		int index = atoi(argv[3]);
		remove_1(&index, clnt);
	}


#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
	
	exit (0);
}
