/*
 * C2.c
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
#include <stdint.h>
#include <math.h>

int32_t function(int32_t a)
{
	if(a >= -2 && a < 2)
	    return a*a;
	else if( a >= 2)
	    return a*a + 4*a + 5;
	else
	    return 4;
}

int main(int argc, char **argv)
{
	int32_t a, tmp;
	scanf("%d", &a);
	if(a == 0) return 0;
	
	tmp = function(a);

	while(a != 0){
		tmp = function(a) > tmp ? function(a) : tmp;
		scanf("%d", &a);
	}
	
	printf("%d\n", tmp);
	
	return 0;
}

