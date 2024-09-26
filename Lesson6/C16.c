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

#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>

void is_prime(int32_t x)
{
	if (x == 1 || x == 0)
	{
		printf("NO");
		return;
	}
    int32_t tmp = 0;
    for (int i = 1; i <= x; i++)
	{
		if(x%i == 0)
			tmp++;
	}
	if (tmp > 2)
	{
		printf("NO");;
	}
	else
	{
		printf("YES");
	}
}

int main(int argc, char **argv)
{
    int32_t x;
    scanf("%d", &x);
	is_prime(x);
    return 0;
}

