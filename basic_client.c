#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;
  char buffer[BUFFER_SIZE];
  
  from_server = client_handshake(&to_server);
  while(1){
    printf("message to server: ");
    fgets(line, BUFFER_SIZE, stdin);
    
    write(to_server, buffer, sizeof(buffer));
    read(from_server, buffer, sizeof(buffer));
    printf("server response: %s\n", buffer);
  }

  return 0;
}
