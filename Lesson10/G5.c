/*
 * G1.c
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
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LINE 1001

int main(int argc, char **argv)
{
    char *input_f = "input.txt";
    char *output_f = "output.txt";
    char line_f[LINE];
    
    char c;
    
    FILE *fp;
    
    if((fp = fopen(input_f, "r")) == NULL )
    {
        perror("Can't find opening file");
        return 1;
    }
    
    int count = 0;
    while( (c = getc(fp)) != EOF)
    {
        line_f[count++] = c;
    }
    line_f[count] = '\0';
    fclose(fp);
    
    int len = strlen(line_f);
    //~ printf("%d\n", len);
    //~ printf("%s\n", line_f);

    if((fp = fopen(output_f, "w")) == NULL)
    {
        perror("Can't find opening file");
        return 1;
    }
    
    for(int i = 0; i < len; i++)
    { 
        if(line_f[i] == 'A' || line_f[i] == 'a')
        {
            line_f[i] += 1;
        }
        else if(line_f[i] == 'B' || line_f[i] == 'b')
        {
            line_f[i] -= 1;
        }    
    }
    //~ printf("%s", line_f);
    fprintf(fp, "%s", line_f);
    fclose(fp);
    return 0;
}

