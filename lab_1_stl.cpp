// lab_1_stl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
    cout << "Время сортировки " << SIZE << " элементов с помощью библиотеки стандартных шаблонов STL: ";
    cout << duration_cast<microseconds>(end - start).count() << " микросекунд(а\\ы)" << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << " ";
    start = high_resolution_clock::now();
    bool result = binary_search(arr.begin(), arr.end(), '!');
    end = high_resolution_clock::now();
    cout << "\nВремя бинарного поиска в массиве из " << SIZE << " элементов с помощью библиотеки стандартных шаблонов STL: ";
    cout << duration_cast<microseconds>(end - start).count() << " микросекунд(а\\ы)" << endl;
    cout << endl;
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
