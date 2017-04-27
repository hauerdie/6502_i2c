/*
Copyright (c) 2015, Dieter Hauer
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include "../i2c.h"

int main()
{
	char r;
	char c;

    printf("     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\r\n");
 
    for (r=0; r < 8; r++) {
        printf("%02X:", r*16);
 
        for (c=0; c < 16; c++) {

            int addr = (r * 16) + c;
        
        if(addr<3 || addr >119) {
        printf("   ");  
        } 
        else 
        	{
        	char ack;
        	i2cStart();
        	ack = i2cWrite(addr<<1);
        	i2cStop();
            switch (ack) 
            	{
            	case 0:
            	    printf(" %02X", addr);
            	    break;
            	case 1:
            	    printf(" --");
            	    break;
            	case 2:
            	    printf(" UU");
            	    break;
            	default:
            	    break;
            	}
       	 	}
        }
        printf("\r\n");
    }
}



