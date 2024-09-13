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
	int num, temp1, temp2, scoreNumber = 0, flag = 0;
	scanf("%d", &num);
	temp = num;
	
	while(temp1 != 0){
	    scoreNumber++;
		temp1 /= 10;
    }
    
    while(num != 0){
	    temp1 = num%10;
	    temp2 = num/10;
	    
	    for (int i = 0; i < scoreNumber-1; i++)
		{
	        if(temp1 == temp2%(10*i))
		}
	    
	    num /=10;
	    scoreNumber--;
	}   		
	return 0;
}

