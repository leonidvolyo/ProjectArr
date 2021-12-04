#include <iostream>
#include <iomanip> // Для модификаторов setw, fixed, setprecision
// setw устанавливает ширину поля для каждого элемента матрицы
// setprecision и fixed устанавливают количество знаков после запятой
// Подробнее http://www.cplusplus.com/reference/ios/defaultfloat/ и http://www.cplusplus.com/reference/ios/fixed/
#include <cstdlib>  // rand ()
using namespace std;

int main()
{
    srand(time(NULL)); // Устанавливаем текущее время, чтобы при запуске rand () каждый раз получать новые псевдорандомные значения
    double a, b;       // Границы интервала [a,b]
    cout << "Enter left border number a: ";
    cin >> a;
    cout << "Enter right border number b: ";
    cin >> b;

    double arr[10][10]; // Двумерный массив случайных чисел

    /*
    Могли бы выделить память динамически (но пока нам это не нужно):

    double **ptrarray = new double* [10]; // 10 строк в массиве
    for (int count = 0; count < 10; count++)
        ptrarray[count] = new double [10]; // и 10 столбцов

        // ptrarray  – массив указателей на выделенный участок памяти под массив вещественных чисел типа double

   // Высвобождение памяти отводимой под двумерный динамический массив:

    for (int count = 0; count < 10; count++)       // 10 – количество строк в массиве
        delete [] ptrarray[count];
    */



    // Записываем в двумерный массив случайные числа
    // RAND_MAX = 32767
    for (int counter_rows = 0; counter_rows < 10; counter_rows++)
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            arr[counter_rows][counter_columns] = (double(rand()) / RAND_MAX) * (b - a) + a; // Генерируем случайные числа типа double равномерно распределённые на интервале [a,b]

    cout << "\n Generated double type array" << endl; // Выводим массив в консоль
    for (int counter_rows = 0; counter_rows < 10; counter_rows++)
    {
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            cout << setw(5) << fixed << setprecision(3) << arr[counter_rows][counter_columns];
        cout << endl;
    }

    double min = arr[0][0]; // min - переменная для хранения минимального значения
    int nom;                // nom - переменная для хранения номера строки с минимальным элементом

    
    // Находим минимальный элемент

    for (int counter_rows = 0; counter_rows < 10; counter_rows++)
    {
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
        {
            if (arr[counter_rows][counter_columns] < min)     // Проверяем каждый элемент на то, меньше ли он предыдущего найденного
            {
                min = arr[counter_rows][counter_columns]; // Если да, сохраняем значение минимального элемента...
                nom = counter_rows; // ... и сохраняем номер строки в nom
            }
        }
    }

    // Выводим минимальный элемент и строку с минимальным элементом
    cout << "\n Min element row number: " << (nom + 1) << endl;  
    cout << "Min element: " << min << endl;




    /*******************************************************************/
    /**************** РАЗОБРАТЬСЯ ДОМА САМОСТОЯТЕЛЬНО ******************/
    /*******************************************************************/


    // Перестанавливаем строки

    if (nom != 0) // Если минимальный элемент не содержится в первой строке (номер строки с минимальным элементом не 0)
    {
        double temp[10]; // Инициализируем временный массив для хранения первой строки
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            temp[counter_columns] = arr[0][counter_columns]; // Сохраняем значения первой строки во временный массив

        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            arr[0][counter_columns] = arr[nom][counter_columns]; // Сохраняем значения строки с минимальным элементом в первой строке двумерного масссива

        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            arr[nom][counter_columns] = temp[counter_columns]; // Перемещаем значения из временного массива на место строки с минимальным элементом

        cout << "\n Array with replaced rows: " << endl; // Вывод массива с перестановленными строками
        for (int counter_rows = 0; counter_rows < 10; counter_rows++)
        {
            for (int counter_columns = 0; counter_columns < 10; counter_columns++)
                cout << setw(7) << fixed << setprecision(3) << arr[counter_rows][counter_columns];
            cout << endl;
        }

    } // Конец IF

    return 0;
}