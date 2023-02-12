// lab_1_stl.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#define SIZE 1000
#include <iostream>
#include <Vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

vector<char> create_array() {
    vector<char> arr;
    char c = NULL;
    for (int i = 0; i < SIZE; i++) {
        do {
            c = rand();
        } while ((int)c <= 32);
        arr.push_back(fabs(c));
    }
    for (int i = 0; i < SIZE; i++)
        cout << arr.at(i) << " ";
    cout << endl;
    return arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    vector<char> arr = create_array();
    auto start = high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    auto end = high_resolution_clock::now();
    cout << "����� ���������� " << SIZE << " ��������� � ������� ���������� ����������� �������� STL: ";
    cout << duration_cast<microseconds>(end - start).count() << " �����������(�\\�)" << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << " ";
    start = high_resolution_clock::now();
    bool result = binary_search(arr.begin(), arr.end(), '!');
    end = high_resolution_clock::now();
    cout << "\n����� ��������� ������ � ������� �� " << SIZE << " ��������� � ������� ���������� ����������� �������� STL: ";
    cout << duration_cast<microseconds>(end - start).count() << " �����������(�\\�)" << endl;
    cout << endl;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
