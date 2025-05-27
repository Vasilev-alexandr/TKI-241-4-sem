#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

class Point {
private:
    int x_;
    int y_;
    std::string label_;

public:
    // Конструкторы
    Point() : x_(0), y_(0), label_("") {}
    Point(int x, int y, const std::string& label) : x_(x), y_(y), label_(label) {}

    // Геттеры
    int x() const { return x_; }
    int y() const { return y_; }
    const std::string& label() const { return label_; }

    // Сеттеры
    void set_x(int x) { x_ = x; }
    void set_y(int y) { y_ = y; }
    void set_label(const std::string& label) { label_ = label; }

    // Оператор сравнения
    bool operator<(const Point& other) const 
    {
        return (x_ < other.x_) || (x_ == other.x_ && y_ < other.y_);
    }

    // Проверка положительности координат
    bool is_positive() const 
    {
        return x_ > 0 && y_ > 0;
    }

    // Преобразование в строку
    std::string to_string() const
    {
        return std::to_string(x_) + " " + std::to_string(y_) + " " + label_;
    }

    // Дружественные операторы ввода/вывода
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

// Реализация оператора ввода
std::istream& operator>>(std::istream& is, Point& p)
{
    return is >> p.x_ >> p.y_ >> p.label_;
}

// Реализация оператора вывода
std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << p.to_string();
}

int main() {
    setlocale(LC_ALL, "RU");

    const std::string filename = "points.txt";  // Имя файла с данными

    // Открытие файла
    std::ifstream fin(filename);
    if (!fin) 
    {
        std::cerr << "Ошибка открытия файла: " << filename << '\n';
        return 1;
    }

    // Создание итераторов для чтения точек и вывода строк
    std::istream_iterator<Point> input_begin(fin), input_end;
    std::ostream_iterator<std::string> output(std::cout, "\n");

    // Замена положительных точек на {0, 0, "A"} и вывод
    std::transform(input_begin, input_end, output,
        [](const Point& p)
        {
            return p.is_positive() ? Point(0, 0, "A").to_string() : p.to_string();
        });

    return 0;
}