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

int prodNum(int num)		//Рекурсивная функция умножения цифр числа
{
    if(num != 0)
        return num % 10 * prodNum( num / 10 );
    else
        return 1;    
}

int main(int argc, char **argv)
{
	int num; 		
	scanf("%d", &num);
	
	if ( (num/1000) != 0){		//Условие, что число трехзначное
	    printf("foulse number");
	    return 0;
    }
   
    printf("%d\n", prodNum(num));
    	
	return 0;
}

