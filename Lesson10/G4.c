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
#define LINE 101

int main(int argc, char **argv)
{
    char *input_f = "input.txt";
    char *output_f = "output.txt";
    char line_f1[LINE];
    char line_f2[LINE];
    
    char c;
    
    FILE *fp;
    
    if((fp = fopen(input_f, "r")) == NULL )
    {
        perror("Can't find opening file");
        return 1;
    }
    
    int count = 0;
    while( (c = getc(fp)) != EOF && c != ' ')
    {
        line_f1[count++] = c;
    }
    line_f1[count] = '\0';
    count = 0;
    while( (c = getc(fp)) != EOF && c != '\n')
    {
        line_f2[count++] = c;
    }
    line_f2[count] = '\0';
    fclose(fp);
    
    int len1 = strlen(line_f1);
    int len2 = strlen(line_f2);
    if((fp = fopen(output_f, "w")) == NULL)
    {
        perror("Can't find opening file");
        return 1;
    }
    int flag = 0;
    for (char i = 0x61; i < 0x7b; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if(i == line_f1[j])
                flag++;
            
        }
        
        if(flag == 1)
        {
            for (int k = 0; k < len2; k++)
            {
                if(i == line_f2[k])
                    flag++;
            }
        }
        else
        {
            flag = 0;
            continue;
        }
        
        if(flag == 2)
        {
        fprintf(fp, "%c ", i);
        }
        else
        {
            flag = 0;
            continue;
        }
        printf("%d\n", flag);
        flag = 0;
        
    }
    
    fclose(fp);
    return 0;
}

