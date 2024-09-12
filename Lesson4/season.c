/*
 * season.c
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
	int season;
	scanf("%d", &season);
	
	switch(season){
		case  1: 
		case  2: printf("winter"); break;
		case  3: 
		case  4: 
		case  5: printf("spring"); break;
		case  6: 
		case  7: 
		case  8: printf("summer"); break;
		case  9: 
		case 10: 
		case 11: printf("autumn"); break;
		case 12: printf("winter"); break;
		default: printf("Error_number");
	}
	return 0;
}

