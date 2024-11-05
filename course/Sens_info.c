/*
==================================================================================
Курсовая работа по теме "Создание консольного приложения - Статистика температуры"
==================================================================================
студент Зеленев Р. А.
*/

#include "temp_functions.h"
#define SIZE 518500 // Размер массива структур

int main(int argc, char **argv)
{
    sens info[SIZE];
    int num;
    int k = 0;
    opterr = 0;
    //======================================= аргументы командной строки
    if (argc == 1)
        printf("No arg, press -f file_name.csv");

    while ((k = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (k)
        {
        case 'h':
            help();
            break;
        case 'f':
            char *file_name = NULL;
            file_name = optarg;
            num = add_info_from_csv(info, file_name);
            // if (num != 0)
                // print_info(info, num);
                break;
        case 'm':
            uint8_t m = *optarg - '0';
            print_month(info, m, num);
            break;
        default:
            printf("No arg, press -f file_name.csv");
            break;
        }
    }
    return 0;
}
