CC = gcc
CFLAGS += -g -I /usr/include/tirpc
LDLIBS += -ltirpc

PROGRAM = RPC_System
CLIENT = $(PROGRAM)_client.c $(PROGRAM)_clnt.c 
SERVER = $(PROGRAM)_svc.c $(PROGRAM)_server.c
HEADER = $(PROGRAM).h 

make: server client 

server: $(SERVER) $(HEADER)
	$(CC) $(CFLAGS) -o $(PROGRAM)_server $(SERVER) -lnsl

client: $(CLIENT) $(HEADER)
	$(CC) $(CFLAGS) -o $(PROGRAM)_client $(CLIENT) -lnsl

clean:
	rm -f RPC_client RPC_server