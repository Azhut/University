#include <iostream>
#include <memory> // для unique_ptr

class str {
private:
    std::unique_ptr<char[]> s; // Указатель на строку символов (без завершающего символа '\0')
    int n; // Размер строки символов

public:
    str() : s(nullptr), n(0) {} // Конструктор по умолчанию

    str(const char *st) // Конструктор, принимающий постоянную строку текста
            : n(0)
    {
        while (st[n] != '\0') n++; // Вычисляем длину входной строки

        s = std::make_unique<char[]>(n);
        for (int i = 0; i < n; i++) s[i] = st[i]; // Копируем строку st
    }

    str(const str& T) // Конструктор копирования
            : s(nullptr), n(T.n)
    {
        if (n > 0) {
            s = std::make_unique<char[]>(n);
            for (int i = 0; i < n; i++) s[i] = T.s[i];
        }
    }


    operator char* () // Преобразование типа str в строку char*
    {
        char* p = new char[n + 1];
        for (int i = 0; i < n; i++) p[i] = s[i];
        p[n] = '\0';
        return p;
    }

    str& operator = (const str& st) // Перегрузка оператора присваивания
    {
        if (&st == this) return *this; // Проверка на самоприсваивание

        if (st.n > 0) {
            s = std::make_unique<char[]>(st.n);
            for (int i = 0; i < st.n; i++) s[i] = st.s[i];
            n = st.n;
        } else {
            s = nullptr;
            n = 0;
        }

        return *this;
    }

    void print() // Печать строки
    {
        for (int i = 0; i < n; i++) std::cout << s[i];
    }

    int length() const { return n; }

    char at(int k) const // Извлечение символа с индексом k
    {
        return (k >= 0 && k < n) ? s[k] : '\0';
    }

    void setchar(char ch, int k) // Установить символ ch в позицию с индексом k
    {
        if (k >= 0 && k < n) s[k] = ch;
    }
};

int main()
{
    setlocale(LC_ALL, "russian");
    str s1, s2("wqeqrwe"), s3(s2), s4("ddddd");
    printf("Привет\n");
    s1 = s2;
    char* p = s4;
    s1.print();
    s2.print();
    std::cout << std::endl << p << std::endl;
    std::cout << s2.length() << "   "<< s2.at(2) << std::endl;
    s3.setchar('z', 2);
    s3.print();

    return 0;
}
