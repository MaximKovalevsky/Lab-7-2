// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//protected нужен для того чтобы они были недоступны вне кода, но доступны предкам.
//при наследовании у предка все переменные приватные. Нужно писать паблика перед названием
#include <iostream>
#include <string>
class Shape
{
protected:
    int x0, y0;//координаты центра фигуры
    int width, height;
    std::string color;
public:
    Shape(int x, int y, int w, int h, std::string c ="")
    {
        this->x0 = x;
        this->y0 = y;
        this->width = x;
        this->height = y;
        this->color = c;

    }
    double area()
    {
        std::cout << "Method is not implemented";
        return 0;
    }
};

class Rectangle : public Shape
{
protected:
    int width, height;
public:
    Rectangle(int w, int h, int x = 0, int y = 0, std::string c = "") : Shape(x,y,w,h,c){}
    double area()
    {
        double s = this->width * this->height;
        std::cout << "Rectangle square is " << s;
        return s;
    }
};

class Square : public Rectangle
{
protected:
    int side;
public:
    Square(int s, int x = 0, int y = 0) : Rectangle(s, s, x, y)
    {
        this->side = s;
    }
    double area()
    {
        double k = this->side * this->side;
        std::cout << "Square square is " << k;
        return k;
    }
};

class Circle : public Shape
{
public:
    int radius;
    Circle(int x0 =0 , int y0 = 0, int r =0, std::string c = "") : Shape(x0,y0, r, r ,c), radius(r){}
    double get_square()
    {
        return 3.141492653 * this->radius * this->radius;
    }
};

class Triangle : public Shape
{
public:
    int side;
    Triangle(int x0, int y0, int a, int h, std::string c = "") : Shape(x0,y0,a,h,c) ,side(a){}
    double area()
    {
        double k = 0.5 * (this->side * this->height);
        std::cout << "Square = " << k;
        return k;
    }

};

int main()
{
    Shape a(5, 3,1,2, "red");
    //a.area();
    Rectangle b(10, 15, 1, -3);
    std::cout << '\n';
    //b.area();
    Square c(2);
    //c.area();
    Circle(1, 2, 3, "blue");
    Triangle d(1, 2, 4, 4, "green");
    d.area();


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
