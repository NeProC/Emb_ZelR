/*
 * B16.c
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

void swap_less_to_more ( int* x, int* y)		//Функция сортировки, меняет переменный
{												//от большего к меньшему
	if( *x < *y ){								//Условие необходимости выполнения ф-ции
    int tmp =  *x;
    *x = *y;
    *y = tmp;	
    }
}

int NOD (int x, int y)							//НОД с помощью алгоритма Евклида
{												//Возвращает НОД
	int tmp;
	while(x%y != 0){
		tmp = x%y;
		x = y;
		y = tmp;
	}
	return y;
}


int main(int argc, char **argv)
{
	int	num1, num2;
	int *pnum1 = &num1, *pnum2 = &num2;
	
	scanf("%d %d", &num1, &num2);
	swap_less_to_more(pnum1, pnum2);

	printf("%d\n", NOD(num1, num2));
	return 0;
}

