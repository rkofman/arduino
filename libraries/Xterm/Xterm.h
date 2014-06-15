/*
  Xterm.h - Library for printing Xterm codes.
  Created by Janis Jakaitis, August 8, 2010.
  Released into the public domain.
*/


#ifndef Xterm_h
#define Xterm_h

#define NORMAL 0
#define BOLD 1
#define UNDERLINED 4
#define BLINK 5
#define INVERSE 7


#include "WProgram.h"

class Xterm
{
  public:
    Xterm();
    void init();
void print(char);
    void print(uint8_t);
    void print(int);
    void print(unsigned int);
    void print(long);
    void print(unsigned long);
      void print(int,int,const char[],int);
    void print(int,int,long int,int);
    void clear();
};

#endif

