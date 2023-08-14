#include <iostream>
#include <string>
using namespace std;

void PrintDinArray(int* arr, int arrActualSize, int arrLogicalSize)
{
    for (int i = 0; i < arrLogicalSize; i++)
    {
        cout << " ";
        cout << arr[i];
    };

    for (int i = arrLogicalSize; i < arrActualSize; i++)
    {
        cout << " ";
        cout << "_";
    };

    cout << endl;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    bool Error = false;
    int arrFactSize = 0; 
    int arrLogicalSize = 0; 
    int userData = 0;
    int* arr = new int[arrFactSize] {};

    cout << "Введите фактичеcкий размер массива:> ";
    cin >> arrFactSize;

    while (!cin.good() || arrFactSize <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Вы ввели неверные даннные. Размер массива положительное целое число.\n";
        cout << "Введите фактичеcкий размер массива:> ";
        cin >> arrFactSize;
    }

    do
    {
        cout << "Введите логичеcкий размер массива:> ";
        cin >> arrLogicalSize;

        while (!cin.good() || arrFactSize <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы ввели неверные даннные.Размер массива это положительное целое число.\n";
            cout << "Введите логичеcкий размер массива:> ";
            cin >> arrLogicalSize;
        }

        if (arrLogicalSize > arrFactSize)
        {
            cout << "Ошибка!!! Логический размер не может превышать фактический!\n";
            Error = false;
        }
        else
        {
            Error = true;
        }

    } while (!Error);

    for (int i = 0; i < arrLogicalSize; i++)
    {
        cout << "Введите arr[" << i << "]:> ";
        cin >> userData;
        arr[i] = userData;
    };

    PrintDinArray(arr, arrFactSize, arrLogicalSize);

    delete[]arr;
    arr = nullptr;
}