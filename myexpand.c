/**
Expand program written for CSCI 296 
@author Rick Beaudet
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{

  int numSpaces, pos, c, tab;

  numSpaces = 0;
  pos = 1;
  tab = 8;

  if(argc != 2)
    {
      fprintf(stderr, "usage: %s <filename>\n", argv[0]);
      exit(-1);
    }

  if(argc == 2)
    {
      fprintf(stderr, "command line error, too few arguments\n");
      exit(-1);
    }
  if(argc == 3)
    {
      if(strcmp(argv[2], "-t")!=0)
        {
          fprintf(stderr, "invalid tabstop command");
          exit(-1);
        }
        else
          {
            tab = atoi(argv[2]);
          }
    }
      if(argc > 3)
        {
          fprintf(stderr, "command line error, too many arguments");
        }
 while((c = getchar()) != EOF)
    {
      if (c == '\t')
        {
          numSpaces = tab  - ((pos - 1) % tab);

          while(numSpaces > 0)
            {
              putchar(' ');
              ++pos;
              --numSpaces;
            }
        }
      else if(c == '\n')
        {
          putchar(c);
          pos = 1;
        }
      else
        {
          putchar(c);
          ++pos;
        }
    }
  return 0;
}
