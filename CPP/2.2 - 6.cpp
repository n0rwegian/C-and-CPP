/*
Подвиг 3. Продолжите программу, в которой объявлен класс Point:

class Point {
    int x, y;
public:
    int get_x() { return x; }
    int get_y() { return y; }
};
Добавьте в этот класс конструктор(ы) так, чтобы были возможны следующие команды:

Point p1 = "10 5"; // x=10, y=5
Point p2 = "-8.7 2.3"; // x=-8, y=2
Point p3 = "14.2 -5.8 point data"; // x=14, y=-5
То есть, из строки выбираются первые два значения, записанные через пробел(ы) и приводятся к типу int. Если
данные оказываются не числовыми, то подставлять значение 0. Например:

Point p_1 = "ab8 2.3"; // x=0, y=2
Point p_2 = "ab8 2cd"; // x=0, y=2 (cd отбрасывается)
Подсказка: для преобразования строк в числа можно использовать функции atoi, atof и другие.

P.S. В программе требуется только объявить класс Point, функцию main не прописывать. На экран ничего выводить
не нужно.
*/

#include <iostream>

#define MAX_LEN 10

class Vector3D {
    int x, y, z;

   public:
    Vector3D(const char *string) { 
        char x_str[MAX_LEN]= {'\0'}, y_str[MAX_LEN] = {'\0'}, z_str[MAX_LEN] = {'\0'};
        int i = 0;
        while ((string[i] != ' ') && (i < MAX_LEN - 1)) {
            x_str[i] = string[i];
            ++i;            
        }
        ++i;
        x_str[i] = '\0';
        
        int j = 0;
        while ((string[i + j] != ' ') && (j < MAX_LEN - 1)) {
            y_str[j] = string[i + j];         
            ++j;
        }
        ++j;
        y_str[j] = '\0';

        int k = 0;
        while ((string[i + j + k] != ' ') && (k < MAX_LEN - 1)) {
            z_str[k] = string[i + j + k];        
            ++k;
        }
        ++k;
        z_str[k] = '\0';

        // printf("%s %s %s\n", x_str, y_str, z_str);       
        
        this->x = atoi(x_str);
        this->y = atoi(y_str);
        this->z = atoi(z_str);
    }
    Vector3D(int* list) {
        x = list[0];
        y = list[1];
        z = list[2];
    }
    Vector3D() : x(0), y(0), z(0) {}
    void get_coords(int& a, int& b, int& c) {
        a = x;
        b = y;
        c = z;
    }
};

int main(void) {
    //Vector3D v1 = "1 2 -5";             // x=1, y=2, z=-5
    //Vector3D v2 = "1.5 2.2 -5.7";       // x=1, y=2, z=-5
    // Vector3D v3 = "1.5 2.2 -5.7 data";  // x=1, y=2, z=-5

    int coords_1[] = {2, 4, 7}, coords_2[] = {5, 3, 1, 0, 20};
    Vector3D v4 = coords_1;  // x=2, y=4, z=7
    Vector3D v5 = coords_2;  // x=5, y=3, z=1

    int cx, cy, cz;
    v5.get_coords(cx, cy, cz);
    printf("%d %d %d", cx, cy, cz);

    return 0;
}

/*
#include <iostream>
#include <string.h>
class Vector3D {
  int x, y, z;

public:
  Vector3D(char *str) : x(0), y(0), z(0) {
    x = std::atoi(str);
    for (int i = 0; i < strlen(str); i++) {
      if (str[i] == ' ') {
        if (y == 0){
          y = atoi(&str[i + 1]);
          continue;}
        if (y != 0 && z == 0) {
          z = atoi(&str[i + 1]);
          break;
        }
      }
    }
  }
  Vector3D(int *arr) : x(0), y(0), z(0) {
    this->x = arr[0];
    this->y = arr[1];
    this->z = arr[2];
  }
  void get_coords(int &a, int &b, int &c) {
    a = x;
    b = y;
    c = z;
  }
};
*/

/*
class Vector3D {
    int x {0}, y {0}, z {0};
public:
    Vector3D(char* str)
    {
        std::stringstream temp;
        std::string sx, sy, sz;
        temp << str;
        temp >> sx >> sy >> sz;

        this->x = atoi(sx.data());
        this->y = atoi(sy.data());
        this->z = atoi(sz.data());
    }
*/

/*
class Vector3D {
    int x, y, z;
public:
    Vector3D(char* str)
    {
        x = atoi(str);
        str = strchr(str, ' ');
        y = atoi(str);
        str++;
        str = strchr(str, ' ');
        z = atoi(str);
    }
*/