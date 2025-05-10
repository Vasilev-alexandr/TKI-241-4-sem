#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

struct point {
    int x, y;
    std::string s;

    // Отношение порядка (оставляем для совместимости)
    bool operator<(const point& other) const 
    {
        return x < other.x || (x == other.x && y < other.y);
    }

    // Преобразование в строку "x y s"
    operator std::string() const
    {
        return std::to_string(x) + " " + std::to_string(y) + " " + s;
    }

    // Проверка положительности координат
    bool is_positive() const
    {
        return x > 0 && y > 0;
    }
};

// Ввод
std::istream& operator>>(std::istream& is, point& p) 
{
    return is >> p.x >> p.y >> p.s;
}

// Вывод
std::ostream& operator<<(std::ostream& os, const point& p)
{
    return os << p.x << ' ' << p.y << ' ' << p.s;
}

int main() {
    setlocale(LC_ALL, "RU");

    const std::string filename = "name";

    std::ifstream fin(filename);
    if (!fin)
    {
        std::cerr << "Ошибка открытия файла: " << filename << '\n';
        return 1;
    }

    std::istream_iterator<point> begin(fin), end;
    std::ostream_iterator<std::string> out(std::cout, "\n");

    // Замена положительных точек на {0, 0, "A"} и вывод
    std::replace_copy_if(begin, end, out, std::mem_fn(&point::is_positive), point{ 0, 0, "A" });
    return 0;
}