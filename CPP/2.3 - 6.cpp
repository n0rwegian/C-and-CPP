/*
Подвиг 4. Продолжите программу, в которой объявлен следующий класс Person:

class Person {
    std::string fio;
    short old {0};
    long salary {0};
public:
    Person(const std::string& fio) : fio(fio)
        { std::cout << "Person(string)" << std::endl; }
    void get_data(std::string& fio, short& old, long& salary)
    {
        fio = this->fio; old = this->old; salary = this->salary;
    }
};
Добавьте в этот класс делегирующий конструктор, который бы принимал три параметра:

std::string fio;
short old;
long salary;
и первое значение fio инициализировал бы вызовом уже имеющегося конструктора.

В функции main создайте объект класса Person с указателем ptr_p на него и передачей в конструктор трех
следующих значений:

"Рахманинов С.В."; 75; 13204

В конце функции main не забудьте освободить ранее выделенную память.
*/

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdio>

class Person {
    std::string fio;
    short old{0};
    long salary{0};

   public:
    Person(const std::string& fio) : fio(fio) { std::cout << "Person(string)" << std::endl; }
    Person(const std::string& fio, short old, long salary) : Person(fio) {
        this->old = old;
        this->salary = salary;
    }
    void get_data(std::string& fio, short& old, long& salary) {
        fio = this->fio;
        old = this->old;
        salary = this->salary;
    }
};

int main(void) {
    Person* ptr_p = new Person("Рахманинов С.В.", 75, 13204);

    std::string fio_p;
    short old_p{0};
    long salary_p{0};

    ptr_p->get_data(fio_p, old_p, salary_p);

    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);
    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    std::cout << fio_p << ' ' << old_p << ' ' << salary_p;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед
    //return 0 или перед освобождением памяти)

    delete ptr_p;

    return 0;
}