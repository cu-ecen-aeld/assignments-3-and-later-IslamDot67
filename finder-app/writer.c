#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[]){
  int result = 0;

  // Setting up logging  
  openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

  // Check Parameters
  if(argc < 3){
    syslog(LOG_ERR, "Expecting 2 parameters, but only %i was provided.\n", argc - 1);
    result =  1;
  }
  else{
    // Retrieve parameters
    char* path_to_file = argv[1];
    char* content = argv[2]; 
    syslog(LOG_DEBUG, "Writing \"%s\" to %s\n", content, path_to_file);

    // Opening file for writing
    FILE* fd = fopen(path_to_file, "w");
    if(fd == NULL){
      syslog(LOG_ERR, "Failed to create file %s.\n", path_to_file);
      result = 1;
    }
    else{
      fputs(content, fd);
      fclose(fd);
    }
  }

  closelog();
  return result;
}
