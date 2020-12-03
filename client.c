/* Just an attempted start to read a file and print the lines */
#include <stdio.h>


int main (void) {
  
  FILE *infile;
  char s, c;
  char input[255];
  int count=0;
  
  infile = fopen("clients.txt", "r");
  
  if (infile == NULL) {
    puts("File could not be accessed,");
  }
  else {
    int i=0;
    
    do {
      fgets(input, sizeof(input), infile);
      printf("File: %d %s", i, input);
      i++;
    }
    while (i<=sizeof(input));
  }
  
  fclose(infile); 
  
}
