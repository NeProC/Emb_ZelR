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
#define LINE 256

int main(int argc, char **argv)
{
    char *input_f = "input.txt";					//Указатель на входной файл
    char *output_f = "output.txt";					//Указатель на выходной файл
    char line_f[LINE];								//Массив для записи содержимого 
    char c;											//Переменная для считывания символа в входном файле
    
    FILE *fp;										//Указатель на файл
    
    //~ if((fp = fopen(input_f, "r")) == NULL)
    if((fp = fopen(input_f, "r")) == NULL)			//Открываем входной файл и проверяем что указатель не пустой
    {
        perror("Error");							//Вывод Error сообщения
        //~ printf("Error occured while opening file \n");
        return 1;
    }
    
    int counter = 0;								//Счетчик количества символов
    
    while ((c = getc(fp)) != EOF && c != '\n')		//Посимвольно считываем charы в файле и проверяем
    {
        line_f[counter++] = c;						//Записываем считанное значение в массив
    }
    line_f[counter] = '\0';							//В конце записываем знак конца строки
    
    fclose(fp);										//Закрываем файл
    
    int len = strlen(line_f);
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        num += (line_f[i] - '0') * pow(10, len - 1 - i);
    }
    int counter_alfa = 0x41, counter_number = 0;
    for (int i = 0; i < num; i++)
    {
        if(i % 2 == 0)
        {
            line_f[i] = counter_alfa++;
        }
        else
        {
            line_f[i] = counter_number + 2 + '0';
            counter_number += 2;
        }
        if(counter_number >= 8)
            counter_number = 0;
    }
    line_f[num] ='\0';
   
    if((fp = fopen(output_f, "w")) == NULL)			//Открываем файл на запись
    {
        perror("Error");
        return 1;
    }
    
    fprintf(fp ,"%s", line_f);
    fclose(fp);
    return 0;
}

