/*
 * max_number.c
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
	int num, t1, t10, t100;
	scanf("%d", &num);
	
	if(num/1000 != 0){
	    printf("foulse_number");
		return 0;
	}
	
	t100 = num/100;
	t10 = (num%100)/10;
	t1 = num%10;
	
	num = t1;
	num = num > t10 ? num : t10;
	num = num > t100 ? num : t100;
	
//	if(num<t10)
//	    num = t10;
//	if(num<t100)
//	    num = t100;
	
	printf("%d\n", num);    
	        
	return 0;
}

