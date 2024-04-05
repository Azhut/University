## ������� ��������:

���� ��� ��������� ����� `str`, �������������� ������ �������� ��� ������������ ������� `'\0'`. ������������ ����� ��������� `std::unique_ptr<char[]>` ��� ���������� ������� ������.

### �������� ����������:

- `str`: �����, �������������� ������ ��������.
- `s`: ����� ��������� �� ������ ��������.
- `n`: ������ ������ ��������.
- `str(const char *st)`: ����������� ��� �������� ������� `str` �� ������ `st`.
- `str(const str& T)`: ����������� �����������.
- `operator char* ()`: ���������� ��������� �������������� ���� `str` � ������ `char*`.
- `operator =`: ���������� ��������� ������������.
- `print()`: ����� ��� ������ ������.
- `length()`: ����� ��� ��������� ����� ������.
- `at()`: ����� ��� ��������� ������� �� �������.
- `setchar()`: ����� ��� ��������� ������� �� �������.

### �������� ������:

1. ��������� ������� `str` � �������������� ��������� �������������.
2. ���������� �������������� ��������� �� ������� �����.
3. ������������������ �������� ������������, ������� � �������� ������ � ��������� ��������.

### ����������:

- ����� `str` ������������� ������� �������� ��� ������ �� ��������, ����� ��� ��������, �����������, ������������ � ������ � ��������.
- ������������ ����� ��������� `std::unique_ptr<char[]>` ��� ��������������� ������������ ������, ��� �������� ������������� ������ ������.
- ��� ������ ������ �� ����� ������������ ����� `print()`, � ��� ��������� ����� ������ - ����� `length()`.