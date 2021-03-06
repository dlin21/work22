#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  
  while(1){
    from_client = server_setup();
    int f = fork();
    if (f){}
    else{
    
      char buffer[BUFFER_SIZE];
      to_client = server_connect(from_client);
      
      while(1){
        // read data from client
        if(read(from_client, buffer, sizeof(buffer)) == 0) break;
      
        int i;
        for(i=0; i<strlen(buffer); i++) buffer[i] = tolower(buffer[i]);
        write(to_client, buffer, sizeof(buffer));
    }
   }
  }
}
