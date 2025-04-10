#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

/**
 * @brief Основная функция программы.
 * Данная программа демонстрирует добавление первой трети элементов списка в обратном порядке в его конец,
 * используя один вызов метода `insert`.
 * @return int Код завершения программы (0 — успех, 1 — ошибка).
 */
int main() {
    // примерный список
    std::list<int> L = { 1, 2, 3, 4, 5, 6 }; 

    // Проверка, что размер кратен 3
    if (L.size() % 3 != 0)
    {
        std::cerr << "Size of list must be divisible by 3." << std::endl;
        return 1;
    }

    // Вычисляем размер первой трети списка
    size_t third = L.size() / 3;

    // Сохраняем первую треть элементов во временный вектор
    std::vector<int> temp;
    auto it = L.begin();
    for (size_t i = 0; i < third; ++i, ++it)
    {
        temp.push_back(*it);
    }

    // Разворачиваем вектор, чтобы получить элементы в обратном порядке
    std::reverse(temp.begin(), temp.end());

    // Вставляем элементы из вектора в конец списка одним вызовом insert
    L.insert(L.end(), temp.begin(), temp.end());

    // Вывод результата
    for (int x : L) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}