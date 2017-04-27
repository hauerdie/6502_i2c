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


char BCDToDecimal (char bcdByte); 
char DecimalToBCD (char decimalByte);

int main()
{

	char status=0;
	char dayOfWeek;
	char dayOfMonth;
	char month;
	char year;

	i2cStart();
	status = i2cWrite( 0xd0 );
	if(status == 0)
	{
		printf("i2c error, no ACK\r\n");
	}
	else
	{
		i2cWrite( 0x03 );
		i2cStop();
		i2cStart();
		i2cWrite( 0xd1 );
		dayOfWeek = BCDToDecimal(i2cRead());
		i2cAck();
		dayOfMonth = BCDToDecimal(i2cRead());
		i2cAck();
		month = BCDToDecimal(i2cRead());
		i2cAck();
		year = BCDToDecimal(i2cRead());
		i2cNack();
		i2cStop();
	}

	switch(dayOfWeek)
	{
		case 1: printf("Sonntag, "); break;
		case 2: printf("Montag, "); break;
		case 3: printf("Dienstag, "); break;
		case 4: printf("Mittwoch, "); break;
		case 5: printf("Donnerstag, "); break;
		case 6: printf("Freitag, "); break;
		case 7: printf("Samstag, "); break;
	}


	printf("%02d.%02d.20%02d\r\n",dayOfMonth,month,year);
	return 0;
}

char BCDToDecimal (char bcdByte)
{
  return (((bcdByte & 0xF0) >> 4) * 10) + (bcdByte & 0x0F);
}
 
char DecimalToBCD (char decimalByte)
{
  return (((decimalByte / 10) << 4) | (decimalByte % 10));
}


