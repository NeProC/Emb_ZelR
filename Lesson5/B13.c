/*
 * B13.c
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
	unsigned int num, score_num = 0, tmp, even = 0, not_even = 0;
	scanf("%d", &num);
	tmp = num;
	
	while (tmp != 0)													//Количество цифр в числе
	{
		score_num++;
		tmp /= 10;
	}
	
	for (int i = score_num; i > 0; i--)									
	{
		num%2 == 0 ? even++ : not_even++;								//Берем остаток от двух, в зависимости от
		num /= 10;														//последней цифры все число четное или 
	}																	//не четное
	printf("%d %d\n", even, not_even);
	return 0;
}

