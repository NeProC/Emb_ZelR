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
#include <stdint.h>

int main(int argc, char **argv)
{
	int32_t n, num, next_num;
	scanf("%d", &n);
	
	while(n != 0){
		num = n%10;
		next_num = n/10;
		while(next_num != 0){
			if(num == next_num%10){
				printf("YES");
				return 0;
			}
			next_num /= 10;
		} 
		n /=10;
	}
	printf("NO");
	return 0;
}

