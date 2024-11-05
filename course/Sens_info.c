/*
==================================================================================
Курсовая работа по теме "Создание консольного приложения - Статистика температуры"
==================================================================================
студент Зеленев Р. А.
*/

#include "temp_functions.h"
#define SIZE 10000 // Размер массива структур

int main(int argc, char **argv)
{
    sens info[SIZE];
    int num;
    int k = 0;
    opterr = 0;
    //======================================= аргументы командной строки

    while ((k = getopt(argc, argv, "hf:m")) != -1)
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
            if(num != 0)
                // print_info(info, num);
                // print_month(info, 1, num);
            break;
        case 'm':
            char m = (char)*optarg;
            printf("%c", m);
            // print_month(info, m, num);
            break;
        default:
            break;
        }
    }
    //==================================================== отработка
    //      int num = add_info_from_csv(info, );
    //  //   add_info_from_csv(info);
    //     printf("num = %d\n", num);
    //     print_info(info, num);

    return 0;
}
