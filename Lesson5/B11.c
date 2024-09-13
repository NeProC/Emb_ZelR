/*
 * B11.c
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
#include <math.h>

int main(int argc, char **argv)
{
	int num, temp, scoreNum = 0, out = 0;
	scanf("%d", &num);
	temp = num;
	
	while(temp != 0){
		scoreNum++;
		temp /= 10;
	}

	
	while(scoreNum != 0){
		out += (num%10) * ( pow(10,scoreNum-1) );
		scoreNum--;
		num /= 10;
	}
	
	printf("%d\n", out);
	return 0;
}

