#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char * token [] = {"{","}","(", ")", ";", "int", "return"};
//how to find identifiers? [a-zA-Z]\w* and integer literals?

int len_token = sizeof(token) / sizeof(token[0]);
int main(int argc, char* argv[])
{
  char const* const fileName = argv[1];
  FILE* file = fopen(fileName, "r");
  char line[256]; //was 256
  char *p = line;
  while (fgets(line, sizeof(line), file)){

    // Find string literals
    do{
      if (isdigit(*p)){ //|| *p == "-" && isdigit(*(p+1)))
        printf("%s", p);
        printf("%ld ", strtol(p,&p,0));
      }
      else
        p++;
               }while(*p!= '\0');
    // Find tokens
    for (int i = 0; i < len_token; i++){
      if (strcmp(line, token[i]) > 0){
        printf("%s", token[i]);
      }
      }

  }
  fclose(file);
  return 0;
}


