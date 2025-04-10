#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

/*
*  @brief Точка входа в программу
*  Программа считывает последовательность вещественных чисел из стандартного ввода
*  и выводит элементы с четными порядковыми номерами(2 - й, 4 - й и т.д.).
*  @return 0 в случае успешного выполнения, 1 при ошибке ввода
*/
int main() {
    vector<double> numbers;

    /*
     * @brief Считывание чисел из стандартного ввода
     * Используется istream_iterator для чтения double значений из cin.
     * Алгоритм copy помещает значения в контейнер numbers через back_inserter.
     * Ввод продолжается до конца потока или ошибки формата.
     */
    copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(numbers));

    if (numbers.size() < 2) {
        cerr << "Ошибка: требуется ввести как минимум 2 числа." << endl;
        return 1;
    }

    /**
     * @brief Фильтрация элементов с нечетными индексами
     * Алгоритм remove_copy_if копирует элементы в ostream_iterator для вывода в cout,
     * пропуская элементы, для которых предикат возвращает true.
     * Лямбда-функция с mutable позволяет изменять index при каждом вызове:
     * - Инкрементирует индекс для каждого элемента
     * - Возвращает true для нечетных позиций (чтобы их пропустить)
     * - Таким образом, в вывод попадают только четные позиции
     */
    remove_copy_if(numbers.begin(), numbers.end(),
        ostream_iterator<double>(cout, " "),
        [index = 0](double) mutable
        { return ++index % 2 != 0; });

    cout << endl;
    return 0;
}