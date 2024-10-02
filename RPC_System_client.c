/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "RPC_System.h"
#include <stdio.h>
#include <stdlib.h>


void rpc_system_program_1( char* host )
{
	CLIENT *clnt;
	void  *result_1;
	ordered  append_1_arg;
	int  *result_2;
	int  query_1_arg;
	void  *result_3;
	int  remove_1_arg;
	clnt = clnt_create(host, RPC_SYSTEM_PROGRAM, RPC_SYSTEM_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror(host);
		exit(1);
	}
	result_1 = append_1(&append_1_arg, clnt);
	if (result_1 == NULL) {
		clnt_perror(clnt, "call failed:");
	}
	result_2 = query_1(&query_1_arg, clnt);
	if (result_2 == NULL) {
		clnt_perror(clnt, "call failed:");
	}
	result_3 = remove_1(&remove_1_arg, clnt);
	if (result_3 == NULL) {
		clnt_perror(clnt, "call failed:");
	}
	clnt_destroy( clnt );
}


main( int argc, char* argv[] )
{
	char *host;

	if(argc < 2) {
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	if (argc < 3) {
		printf("No request type provided");
		exit(1);
	}

	host = argv[1];
	rpc_system_program_1( host );

	CLIENT *clnt = clnt_create(host, RPC_SYSTEM_PROGRAM, RPC_SYSTEM_VERS, "udp");

	char req = argv[2];

	if (req == 'a' || req == 'A'){
		if (argc < 11) {
			printf("Append: too few arguments");
			exit(1);
		}
		if (argc > 11) {
			printf("Append: %d remaining unused arguments\n", (argc - 11));
		}
		printf("Adding 8 elements\n");
		int input[8];
		
		for (int i = 0; i < 8; i++) {
			input[i] = atoi(argv[i+3]);
		}

		// Add elements to new ordered list
		ordered list;
		list.ordered_len = 8;
		list.ordered_val = input;

		append_1(&list, clnt);
	}
	else if (req == 'q' || req == 'Q') {
		if (argc < 4) {
			printf("Query: too few arguments");
		}
		if (argc > 11) {
			printf("Query: %d remaining unused arguments\n", (argc - 4));
		}
		printf("Query at element %s\n", argv[3]);

		query_1(argv[3], clnt);
	}
	else if (req == 'r' || req == 'r'){
		if (argc < 4) {
			printf("Remove: too few arguments");
		}
		if (argc > 11) {
			printf("Remove: %d remaining unused arguments\n", (argc - 4));
		}
		printf("Removing element %s\n", argv[3]);

		remove_1(argv[3], clnt);
	}

	printf("Current list: ");
}
