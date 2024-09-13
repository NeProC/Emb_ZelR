/*
 * B7.c
 * 
 * Copyright 2024 R.Zelenev <R.Zelenev@NB-592>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int num, x0=0, x1=0, x2=0, x3=0, x4=0, x5=0, x6=0, x7=0, x8=0, x9=0, tmp;
	scanf("%d", &num);
	
	while(num != 0){
		tmp = num%10;
		switch(tmp){
			case 0: x0++; break;
			case 1: x1++; break;
			case 2: x2++; break;
			case 3: x3++; break;
			case 4: x4++; break;
			case 5: x5++; break;
			case 6: x6++; break;
			case 7: x7++; break;
			case 8: x8++; break;
			case 9: x9++; break;
			default: break;
		}
		num /= 10;	
	}
	if( x0 > 1 || x1 > 1 || x2 > 1 || x3 > 1 || x4 > 1 || x5 > 1 || x6 > 1 || x7 > 1 || x8>1 || x9>1 )
	    printf("YES");
	else
	{
		printf("NO");
	}    
	 		
	return 0;
}

