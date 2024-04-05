#include <iostream>
#include <memory> // ��� shared_ptr

class str {
private:
    std::shared_ptr<char[]> s; // ��������� �� ������ �������� (��� ������������ ������� '\0')
    int n; // ������ ������ ��������

public:
    str() : s(nullptr), n(0) {} // ����������� �� ���������

    str(const char *st) // �����������, ����������� ���������� ������ ������
            : n(0)
    {
        while (st[n] != '\0') n++; // ��������� ����� ������� ������

        s = std::shared_ptr<char[]>(new char[n]);
        for (int i = 0; i < n; i++) s.get()[i] = st[i]; // �������� ������ st
    }

    str(const str& T) // ����������� �����������
            : s(nullptr), n(T.n)
    {
        if (n > 0) {
            s = std::shared_ptr<char[]>(new char[n]);
            for (int i = 0; i < n; i++) s.get()[i] = T.s.get()[i];
        }
    }

    ~str() = default;

    operator char* () // �������������� ���� str � ������ char*
    {
        char* p = new char[n + 1];
        for (int i = 0; i < n; i++) p[i] = s.get()[i];
        p[n] = '\0';
        return p;
    }

    str& operator = (const str& st) // ���������� ��������� ������������
    {
        if (&st == this) return *this; // �������� �� ����������������

        if (st.n > 0) {
            s = std::shared_ptr<char[]>(new char[st.n]);
            for (int i = 0; i < st.n; i++) s.get()[i] = st.s.get()[i];
            n = st.n;
        } else {
            s = nullptr;
            n = 0;
        }

        return *this;
    }

    void print() // ������ ������
    {
        for (int i = 0; i < n; i++) std::cout << s.get()[i];
    }

    int length() const { return n; }

    char at(int k) const // ���������� ������� � �������� k
    {
        return (k >= 0 && k < n) ? s.get()[k] : '\0';
    }

    void setchar(char ch, int k) // ���������� ������ ch � ������� � �������� k
    {
        if (k >= 0 && k < n) s.get()[k] = ch;
    }
};

//int main()
//{
//    setlocale(LC_ALL, "russian");
//    str s1, s2("wqeqrwe"), s3(s2), s4("ddddd");
//    printf("������\n");
//    s1 = s2;
//    char* p = s4;
//    s1.print();
//    s2.print();
//    std::cout << std::endl << p << std::endl;
//    std::cout << s2.length() << "   "<< s2.at(2) << std::endl;
//    s3.setchar('z', 2);
//    s3.print();
//
//    return 0;
//}
