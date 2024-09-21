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

int32_t power(int32_t n, int32_t p)
{
	if(p == 0) return 1;
	uint32_t tmp = n;
	
	for (int i = 1; i < p; i++){
		tmp *= n;
	}
	
	return tmp;
}

uint32_t calculus( uint32_t N, uint32_t P)
{
	uint32_t new_num = 0, i = 0;
	
	while (N != 0){
		new_num += (N % P) * power(10,i);
		i++;
		N /= P;
	}
	
	return new_num;
}

int main(int argc, char **argv)
{
	int32_t N, P;
	scanf("%d %d", &N, &P);
	printf("%d\n", calculus(N,P));
	return 0;
}

