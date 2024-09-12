/*
 * sum_mult_3.c
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

int sum3(int a, int b, int c)
{
	return a + b + c;	
}	

int comp3(int a, int b, int c)
{
    return a * b * c;
}	

int main(int argc, char **argv)
{
	int x1, x2, x3;
	scanf("%d %d %d", &x1, &x2, &x3);
    
    printf("%d\n", sum3(x1,x2,x3));
    printf("\t%d\n", comp3(x1,x2,x3));
	
	return 0;
}
