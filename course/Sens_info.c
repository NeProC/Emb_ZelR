/*
==================================================================================
Курсовая работа по теме "Создание консольного приложения - Статистика температуры"
==================================================================================
студент Зеленев Р. А.
*/

#include "temp_functions.h"
// #define SIZE 512 // Размер массива структур
enum
{
    SIZE = 200000
};
#define DEBUG fprintf(stderr, "debug in %d line\n", __LINE__)

int main(int argc, char **argv)
{
    sens info[SIZE];
    int num;
    int k = 0;
    char *file_name = NULL;
    char m;
    //   printf("Maximum Size of Array: %lu bytes\n", SIZE_MAX);
    //   printf("%d\n", sizeof(sens));
    //======================================= аргументы командной строки
    opterr = 0;
    while ((k = getopt(argc, argv, "hf:m:o:")) != -1)
    {
        switch (k)
        {
        case 'h':
            help();
            break;
        case 'f':
            file_name = optarg;
            //            num = add_info_from_csv(info, file_name);
            // if(num != 0)
            //      print_info(info, num);
            break;
        case 'm':
            m = *optarg - '0';
            //           print_month(info, m, num);
            print_month_from_file(file_name, m);
            break;
        case 'o':
            m = *optarg - '0';
            out_txt_mon(file_name, m);
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
