#include "temp_functions.h"
#include <stdint.h>

void add_rec(sens info[], int num, uint16_t year, uint8_t month,
             uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
    info[num].year = year;
    info[num].month = month;
    info[num].day = day;
    info[num].hour = hour;
    info[num].minute = minute;
    info[num].t = t;
    return;
}

int add_info(sens info[]) // Ввод фикс данных
{
    int counter = 0;
    add_rec(info, counter++, 2021, 9, 16, 23, 55, 9);
    add_rec(info, counter++, 2021, 9, 2, 23, 55, -9);
    add_rec(info, counter++, 2021, 1, 7, 23, 55, 8);
    add_rec(info, counter++, 2021, 9, 5, 23, 55, -10);
    add_rec(info, counter++, 2021, 9, 5, 23, 56, 1);
    return counter;
}

int add_info_from_csv(sens info[], char *filename) // Из scv
{
    char *input_f = filename;
    char buffer[1024];
    FILE *fp;

    if ((fp = fopen(input_f, "r")) == NULL)
    {
        perror("Can't find opening file");
        return 1;
    }
    int num = 0;

    while (fgets(buffer, sizeof(buffer), fp))
    {
        if (sscanf(buffer, "%d;%d;%d;%d;%d;%d", &info[num].year, &info[num].month, &info[num].day, &info[num].hour, &info[num].minute, &info[num].t) == 6)
            num++;
        if (num >= 199999)
        {
            fclose(fp);
            return num;
        }
    }

    fclose(fp);
    return num;
}

uint64_t date_to_num(sens *info)
{
    return ((uint64_t)info->year << 32) | (info->month << 24) | (info->day << 16) | (info->hour << 8) | (info->minute << 0);
    //~ return ((info->year) * pow(2,32) + (info->month) * pow(2,24) + (info->day) * pow(2,16) + (info->hour) * pow(2,8) + (info->minute));
}

void print_info(sens info[], int num)
{
    printf("<========================================>\n");
    for (int32_t i = 0; i < num; i++)
    {
        printf("%04d - %02d - %02d - %02d - %02d\tt = %3d%cC\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].minute,
               info[i].t,
               0x27);
    }
    return;
}

void swap_ij(sens info[], int i, int j)
{
    sens tmp = info[i];
    info[i] = info[j];
    info[j] = tmp;
    return;
}

void sort_t(sens info[], int num)
{
    for (int32_t i = 0; i < num; i++)
    {
        for (int32_t j = i; j < num; j++)
        {
            if (info[i].t < info[j].t)
            {
                swap_ij(info, i, j);
            }
        }
    }
    return;
}

void sort_time(sens *info, int num)
{
    for (int32_t i = 0; i < num; i++)
    {
        for (int32_t j = i; j < num; j++)
        {
            if (date_to_num(info + i) < date_to_num(info + j))
                swap_ij(info, i, j);
        }
    }
    return;
}

void middle_t_in_month(sens info[], int num, int8_t month)
{
    int count = 0, sum = 0;
    for (int32_t i = 0; i < num; i++)
    {
        if (month == (info[i].month))
        {
            count++;
            sum += info[i].t;
        }
    }

    float mid = ((float)sum / count);
    printf("Middle t in %d month = %2.2lf \n", month, mid);
    return;
}

void min_in_month(sens info[], int num, int8_t month)
{
    int8_t min = info[0].t;

    for (int32_t i = 1; i < num; i++)
    {
        min = min < info[i].t ? min : info[i].t;
    }

    printf("Minimal t in %d month = %d\n", month, min);
    return;
}

void max_in_month(sens info[], int num, int8_t month)
{
    int8_t max = info[0].t;

    for (int32_t i = 1; i < num; i++)
    {
        max = max > info[i].t ? max : info[i].t;
    }

    printf("Maximal t in %d month = %d\n", month, max);
    return;
}

void middle_t_in_year(sens info[], int num, int16_t year)
{
    int count = 0, sum = 0;
    for (int32_t i = 0; i < num; i++)
    {
        if (year == (info[i].year))
        {
            count++;
            sum += info[i].t;
        }
    }

    float mid = ((float)sum / count);
    printf("Middle t in %d = %2.2lf \n", year, mid);
    return;
}

void min_in_year(sens info[], int num, int16_t year)
{
    int16_t min = info[0].year;

    for (int32_t i = 1; i < num; i++)
    {
        min = min < info[i].t ? min : info[i].t;
    }

    printf("Minimal t in %d = %d\n", year, min);
    return;
}

void max_in_year(sens info[], int num, int16_t year)
{
    int16_t max = info[0].t;

    for (int32_t i = 1; i < num; i++)
    {
        max = max > info[i].t ? max : info[i].t;
    }

    printf("Maximal t in %d = %d\n", year, max);
    return;
}

void help(void)
{
    printf("-h\thelp massege");
    return;
}

void del_rec(sens info[], int num)
{
    info[num].year = 0;
    info[num].month = 0;
    info[num].day = 0;
    info[num].hour = 0;
    info[num].minute = 0;
    info[num].t = 0;
    return;
}

int convert_in_num(char buf[])
{
    int counter = 0;
    int num;
    while (*(buf + counter) != ';')
    {
        counter++;
    }
}

void print_month(sens info[], char month, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (info[i].month == month)
        {
            printf("%04d - %02d - %02d - %02d - %02d\tt = %3d%cC\n",
                   info[i].year,
                   info[i].month,
                   info[i].day,
                   info[i].hour,
                   info[i].minute,
                   info[i].t,
                   0x27);
        }
    }
    return;
}

void print_month_from_file(char *filename, char month)
{
    char *input_f = filename;
    char buffer[1024];
    FILE *fp;
    sens tmp[1];
    uint32_t line = 0;

    if ((fp = fopen(input_f, "r")) == NULL)
    {
        perror("Can't find opening file");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp))
    {
        line++;
        if (sscanf(buffer, "%d;%d;%d;%d;%d;%d", &tmp[0].year, &tmp[0].month, &tmp[0].day, &tmp[0].hour, &tmp[0].minute, &tmp[0].t) == 6)
        {
            if (tmp->month == month)
            {
                printf("%04d - %02d - %02d - %02d - %02d\tt = %3d%cC\n",
                       tmp[0].year,
                       tmp[0].month,
                       tmp[0].day,
                       tmp[0].hour,
                       tmp[0].minute,
                       tmp[0].t,
                       0x27);
            }
        }
        else
        {
            printf("Error or missing value in line %d\n", line);
        }
    }

    fclose(fp);
    return;
}

void out_txt_mon(char *filename, char month)
{
    char *output_f = "output_month.txt";
    FILE *fp_out;
    
    if((fp_out = fopen(output_f, "w")) == NULL)
    {
        perror("Can't open file");
        return;
    }
    
    char *input_f = filename;
    char buffer[1024];
    FILE *fp_in;
    
    if((fp_in = fopen(input_f, "r")) == NULL)
    {
        perror("Can't find opening file");
        return;
    }
    
    sens tmp[1];
    int32_t line = 0;
    while (fgets(buffer, sizeof(buffer), fp_in))
    {
        line++;
        if (sscanf(buffer, "%d;%d;%d;%d;%d;%d", &tmp[0].year, &tmp[0].month, &tmp[0].day, &tmp[0].hour, &tmp[0].minute, &tmp[0].t) == 6)
        {
           if ((tmp->month) == month)
                fprintf(fp_out, "%04d - %02d - %02d - %02d - %02d\tt = %3d%cC\n",
                       tmp[0].year,
                       tmp[0].month,
                       tmp[0].day,
                       tmp[0].hour,
                       tmp[0].minute,
                       tmp[0].t,
                       0x27);
        }
        // else
        // {
        //     fputs("In line  error  or missing value\n", fp_out);
        // }
    }    
    fclose(fp_in);
    fclose(fp_out);

    return;
}