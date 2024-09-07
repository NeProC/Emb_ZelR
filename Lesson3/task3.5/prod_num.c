/*
 * prod_num.c
 * 
 * Copyright 2024 roman <roman@DESKTOP-RM33TSB>
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
	int num, x1, x10, x100;			
	scanf("%d", &num);
	
	if ( (num/1000) != 0){		//Условие, что число трехзначное
	    printf("foulse number");
	    return 0;
    }
    
    x1 = num%10;				//Единицы
    x10 = (num%100)/10;			//Десятки
    x100 = num/100; 			//Сотни
    
//    printf("%d\n", x1);
//    printf("%d\n", x10);
//    printf("%d\n", x100);
    
    printf("%d\n", x1 * x10 * x100);
    	
	return 0;
}

