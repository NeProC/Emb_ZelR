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
#define LINE 256

int main(int argc, char **argv)
{
    char *input_f = "input.txt";
    char *output_f = "output.txt";
    char line_f[LINE];
    char c;
    
    FILE *fp;
    
    if((fp = fopen(input_f, "r")) == NULL)
    {
        perror("Error");
        return 1;
    }
    
    int counter = 0;
    
    while ((c = getchar()) != EOF && c != '\n')
    {
        line_f[counter++];
    }
    line_f[counter] = '\n';
    
    fclose(fp);
    
    if((fp = fopen(output_f, "w")) == NULL)
    {
        perror("Error file");
        return 1;
    }
    
    for(int32_t i = 0; i < 3; i++)
    {
        fprintf(fp, "%s", line_f);
        fprintf(fp, ", ");
    }
    fprintf(fp, " %d", counter);
    fclose(fp);
    return 0;
}

