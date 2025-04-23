#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    if (n < 3)
    {
        std::cout << "Недостаточно элементов\n";
        return 0;
    }

    std::vector<int> V(n);
    std::cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> V[i];
    }

    std::multiset<int> ms(V.begin(), V.end());

    int min_val = *std::min_element(V.begin(), V.end());
    int max_val = *std::max_element(V.begin(), V.end());

    if (min_val == max_val)
    {
        std::cout << "Все элементы одинаковые, нечего выводить.\n";
        return 0;
    }

    auto low = ms.upper_bound(min_val);
    auto high = ms.lower_bound(max_val);

    if (low == high)
    {
        std::cout << "Нет элементов между минимальным и максимальным.\n";
    }
    else
    {
        std::copy(low, high, std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    return 0;
}