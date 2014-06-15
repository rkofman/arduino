/*
  Xterm.cpp - Library for printing Xterm codes.
  Created by Janis Jakaitis, August 8, 2010.
  Released into the public domain.
  Data from http://invisible-island.net/xterm/ctlseqs/ctlseqs.html
*/


#include "WProgram.h"
#include "Xterm.h"

Xterm::Xterm(){
}

void Xterm::init()
{
  Serial.print("\eSP F");  	// tell to use 7-bit control codes
  Serial.print("\e[?25l"); 	// hide cursor
  Serial.print("\e[?12l");	// disable cursor highlighting
  Serial.print("\e[2J"); 	// clear screen
}

void Xterm::print(int r, int c, const char t[],int m)
{
	switch (m) // m = mode
	{
	case 0: // Normal
		Serial.print("\e[0m");
		break;
	case 1: // Bold
		Serial.print("\e[1m");
		break;
	case 4: // Underlined
		Serial.print("\e[4m");
		break;
	case 5:  // Blink
		Serial.print("\e[5m");
		break;
	case 7: // Inverse
		Serial.print("\e[7m");
		break;
	default: // Normal
		Serial.print("\e[0m");
	}

	Serial.print("\e[");  	// escape symbol
	Serial.print(r); 	// row 	
	Serial.print(";");
	Serial.print(c);	// column
	Serial.print("f");
	Serial.print(t);	// text
}

void Xterm::print(int r, int c, long int t,int m)
{
	switch (m) // m = mode
	{
	case 0: // Normal
		Serial.print("\e[0m");
		break;
	case 1: // Bold
		Serial.print("\e[1m");
		break;
	case 4: // Underlined
		Serial.print("\e[4m");
		break;
	case 5:  // Blink
		Serial.print("\e[5m");
		break;
	case 7: // Inverse
		Serial.print("\e[7m");
		break;
	default: // Normal
		Serial.print("\e[0m");
	}

	Serial.print("\e[");  	// escape symbol
	Serial.print(r); 	// row 	
	Serial.print(";");
	Serial.print(c);	// column
	Serial.print("f");
	Serial.print(t);	// text
	Serial.print("\e[0m");
}



void Xterm::clear()
{
	Serial.print("\e[2J"); // clear screen
}
