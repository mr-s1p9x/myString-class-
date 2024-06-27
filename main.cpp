#include <iostream>
#include <cstring> // для работы с C-строками
using namespace std;

class MyString {
private:
    char* str; // указатель на строку
    int length; // длина строки

public:
    // Конструктор по умолчанию
    MyString() : length(80) {
        str = new char[length + 1];
        str[0] = '\0'; // инициализация пустой строки
    }

    // Конструктор произвольного размера
    MyString(int size) : length(size) {
        str = new char[length + 1];
        str[0] = '\0'; // инициализация пустой строки
    }

    // Конструктор, инициализирующий строку от пользователя
    MyString(const char* userStr) {
        length = strlen(userStr);
        str = new char[length + 1];
        strcpy(str, userStr);
    }

    // Деструктор
    ~MyString() {
        delete[] str;
    }

    // Метод ввода строки с клавиатуры
    void input() {
        cout << "Введите строку: ";
        cin.getline(str, length + 1);
    }

    // Метод вывода строки на экран
    void output() const {
        cout << str << endl;
    }

    // Метод копирования строки
    void MyStrcpy(MyString& obj) {
        if (this == &obj) return; // проверка на самокопирование
        delete[] str; // освобождаем старую память
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }

    // Метод поиска подстроки в строке
    bool MyStrStr(const char* substr) {
        return strstr(str, substr) != nullptr;
    }

    // Метод поиска символа в строке
    int MyChr(char c) {
        char* pos = strchr(str, c);
        if (pos != nullptr) {
            return pos - str;
        }
        return -1;
    }

    // Метод возвращающий длину строки
    int MyStrLen() {
        return strlen(str);
    }

    // Метод объединения строк
    void MyStrCat(MyString& b) {
        char* newStr = new char[length + b.length + 1];
        strcpy(newStr, str);
        strcat(newStr, b.str);
        delete[] str;
        str = newStr;
        length += b.length;
    }

    // Метод удаления указанного символа
    void MyDelChr(char c) {
        char* newStr = new char[length + 1];
        int newIndex = 0;
        for (int i = 0; i < length; ++i) {
            if (str[i] != c) {
                newStr[newIndex++] = str[i];
            }
        }
        newStr[newIndex] = '\0';
        delete[] str;
        str = newStr;
        length = strlen(str);
    }

    // Метод сравнения строк
    int MyStrCmp(MyString& b) {
        int result = strcmp(str, b.str);
        if (result < 0) return -1;
        if (result > 0) return 1;
        return 0;
    }
};

// Основная функция для тестирования класса
int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3;

    s1.output(); // Hello
    s2.output(); // World

    cout << "Копирование строки s2 в s3" << endl;
    s3.MyStrcpy(s2);
    s3.output(); // World

    cout << "Объединение строк s1 и s2" << endl;
    s1.MyStrCat(s2);
    s1.output(); // HelloWorld

    cout << "Поиск подстроки 'World' в s1: " << s1.MyStrStr("World") << endl; // 1 (true)
    cout << "Поиск символа 'W' в s1: " << s1.MyChr('W') << endl; // 5

    cout << "Длина строки s1: " << s1.MyStrLen() << endl; // 10

    cout << "Удаление символа 'l' из s1" << endl;
    s1.MyDelChr('l');
    s1.output(); // HeoWord

    cout << "Сравнение строк s1 и s2: " << s1.MyStrCmp(s2) << endl; // 1 (s1 больше чем s2)

    return 0;
}
