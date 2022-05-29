
CC = g++
CLIENT_FILE = simple-client.cpp
SERVER_FILE = simple-server.cpp

all: client server

client: $(CLIENT_FILE)
	$(CC) $(CLIENT_FILE) -o client

server: $(SERVER_FILE)
	$(CC) $(SERVER_FILE) -o server

clean:
	rm -f client server
