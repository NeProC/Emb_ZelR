include <stdint.h>

typedef struct
{ // Структура данных датчика
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
} sens;

void add_rec(sens info[], int num, uint16_t year, uint8_t month,
             uint8_t day, uint8_t hour, uint8_t minute, int8_t t); // Функция добавления структуры в массив
int add_info(sens info[]);                                         // Ф-ция добавления значений
void print_info(sens info[], int num);                             // Вывод данных
void swap_ij(sens info[], int i, int j);                           // Меняет местами структуры в массиве
void sort_t(sens info[], int num);                                 // Сортировка по температуре
uint64_t date_to_num(sens *info);                                  // Функция приведения времени к числовому значению для сравнения
void sort_time(sens info[], int num);                              // Сортировка по времени измерения
void middle_t_in_month(sens info[], int num, int8_t month);        // Среднемесячная температура в месяце за все года
void min_in_month(sens info[], int num, int8_t month);             // Минимальная температура в месяце за все года
void max_in_month(sens info[], int num, int8_t month);             // Максимальная температура в месяце за все года
void middle_t_in_year(sens info[], int num, int16_t year);         // Средняя температура за год
void min_in_year(sens info[], int num, int16_t year);              // Минимальная температура за выбраный год
void max_in_year(sens info[], int num, int16_t year);              // Максимальная температура за выбраный год
