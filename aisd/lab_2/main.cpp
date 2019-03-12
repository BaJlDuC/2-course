#include <iostream>

using namespace std;

const int somNumber = 25;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    int array[] = {2, 4, 6, 8, 0, 0, 0, 0, 7, 5, 3, 1};
    int button = 0;
    int left = 3;
    int right = 8;
    int leftArray = left;
    int rightArray = right;
    int lastLeftArrayElement = array[leftArray];
    int lastRightArrayElement = array[rightArray];
    int freeIndexStart = somNumber;
    int freeIndexEnd = somNumber;

    bool leftStart = true;
    bool rightStart = true;

    while (button != 9)
    {
        freeIndexStart = somNumber;
        freeIndexEnd = somNumber;
        leftArray = left;
        rightArray = right;
        cout << "1. Состояние массива" << endl;
        cout << "2. Выбрать стек" << endl;
        cout << "9. Выход" << endl;
        cout << endl;
        cin >> button;
        cout << endl;
        switch (button)
        {
        case 1:
            cout << "Массив на текущий момент: ";
            for (int i = 0; i <= 11; i++) //!= 12
            {
                cout << array[i] << ' '; // вывод элементов массива
                if (array[i] == 0)
                {
                    if (freeIndexStart == somNumber)
                    {
                        freeIndexStart = i;
                    }
                    freeIndexEnd = i;
                }
            }
            cout << endl;
            if ((freeIndexStart != somNumber) && (freeIndexEnd != somNumber))
            {
                if (freeIndexStart == freeIndexEnd)
                {
                    cout << " Остался только один свободный индекс: " << freeIndexStart << endl;
                }
                else
                {
                    cout << "Интервал свободных индексов: [" << freeIndexStart << "; " << freeIndexEnd << "] " << endl;
                }
            }
            else
            {
                cout << "Свободных индексов не осталось " << endl;
            }

            if ((array[left] != 0) && (leftStart == true))
            {
                cout << "Стек1(слева, вывод в обратном порядке): ";
                while (leftArray >= 0)
                {
                    cout << array[leftArray] << ' ';
                    leftArray--;
                }
                cout << endl;
            }
            else
            {
                cout << "Стек1(слева) пуст" << endl;
            }

            if ((array[right] != 0) && (rightStart == true))
            {
                cout << "Стек2(справа, вывод в обратном порядке): ";
                while (rightArray != 12)
                {
                    cout << array[rightArray] << ' ';
                    rightArray++;
                }
                cout << endl;
            }
            else
            {
                cout << "Стек2(справа) пуст" << endl;
            }
            break;
        case 2:
            cout << "     Выберите стек" << endl;
            while (button != 3)
            {
                cout << "1. Стек1(слева)" << endl;
                cout << "2. Стек2(справа)" << endl;
                cout << "3. Вернуться" << endl;
                cout << endl;

                cin >> button;
                cout << endl;
                if (button == 1) // потом вынести в функцию
                {
                    while (button != 4)
                    {
                        cout << "     Выбран Стек1(слева)" << endl;
                        cout << "1. Добавить элемент" << endl;
                        cout << "2. Удалить элемент" << endl;
                        cout << "3. Вывести на экран элементы стека" << endl;
                        cout << "4. Назад" << endl;
                        cout << endl;

                        cin >> button;
                        cout << endl;
                        if (button == 3) //кнопка показа элементов
                        {
                            leftArray = left;
                            if ((array[left] != 0) && (leftStart == true))
                            {
                                cout << "Элементы выбранного стека: ";
                                while (leftArray >= 0)
                                {
                                    cout << array[leftArray] << ' ';
                                    leftArray--;
                                }
                            }
                            else
                            {
                                cout << "Выбранный стек пуст" << endl;
                            }
                            cout << endl;
                        }

                        if (button == 1) // кнопка добавления элемента в стек
                        {
                            if ((array[left + 1] == 0) || (array[left] == 0)) // было без ||
                            {
                                switch (array[left]) //определяем позицию текущей вершины
                                {
                                case 0:
                                    array[left] = 2;
                                    leftStart = true;
                                    cout << "Стек успешно увеличен. Добавлен первый элемент " << array[left] << endl;
                                    break;
                                case 2:
                                    array[left + 1] = 4;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 4:
                                    array[left + 1] = 6;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 6:
                                    array[left + 1] = 8;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 8:
                                    array[left + 1] = 10;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 10:
                                    array[left + 1] = 12;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 12:
                                    array[left + 1] = 14;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 14:
                                    array[left + 1] = 16;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 16:
                                    array[left + 1] = 18;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 18:
                                    array[left + 1] = 20;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 20:
                                    array[left + 1] = 22;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << endl;
                                    break;
                                case 22:
                                    array[left + 1] = 24;
                                    left++;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[left] << ',';
                                    cout << " достигнут максимальный размер" << endl;
                                    break;
                                case 24: // не нужно
                                    cout << "Ошибка. Стек имеет максимальный размер. Массив полон." << endl;
                                    break;
                                }
                            }
                            else
                            {
                                if (left == 11)
                                {
                                    cout << "Ошибка. Стек имеет максимальный размер. Массив полон" << endl;
                                }
                                else
                                {
                                    cout << "Ошибка. Пересечение со вторым стеком, добавление элемента невозможно" << endl;
                                }
                            }
                        }

                        if (button == 2) // кнопка удаления элемента
                        {
                            switch (array[left])
                            {
                            case 24:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 22:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 20:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 18:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 16:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 14:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 12:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 10:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 8:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 6:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 4:
                                cout << "Успешно удалена текущая вершина стека - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " Новая вершина стека - " << array[left] << endl;
                                break;
                            case 2:
                                cout << "Успешно удален единственный элемент стека - " << array[left] << '.';
                                array[left] = 0;
                                leftStart = false;
                                cout << " В стеке не осталось элементов" << endl;
                                break;
                            case 0:
                                cout << "Ошибка, стек пуст" << endl;
                                break;
                            default:
                                cout << "Ошибка, стек пуст" << endl;
                                break;
                            }
                        }
                    }
                }

                if (button == 2)
                {
                    while (button != 4)
                    {
                        cout << "     Выбран Стек2(справа)" << endl;
                        cout << "1. Добавить элемент" << endl;
                        cout << "2. Удалить элемент" << endl;
                        cout << "3. Вывести на экран элементы стека" << endl;
                        cout << "4. Назад" << endl;
                        cout << endl;

                        cin >> button;

                        cout << endl;
                        if (button == 3) // кнопка вывода на экран элементов стека
                        {
                            rightArray = right;
                            if ((array[right] != 0) && (rightStart == true))
                            {
                                cout << "Элементы выбранного стека: ";
                                while (rightArray != 12)
                                {
                                    cout << array[rightArray] << ' ';
                                    rightArray++;
                                }
                                cout << endl;
                            }
                            else
                            {
                                cout << "Выбранный стек пуст" << endl;
                            }
                        }

                        if (button == 1) // кнопка добавления элемента
                        {
                            if ((array[right - 1] == 0) || (array[right] == 0))
                            {
                                switch (array[right])
                                {
                                case 0:
                                    array[right] = 1;
                                    cout << "Стек успешно увеличен. Добавлен первый элемент " << array[right] << endl;
                                    rightStart = true;
                                    break;
                                case 1:
                                    right--;
                                    array[right] = 3;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 3:
                                    right--;
                                    array[right] = 5;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 5:
                                    right--;
                                    array[right] = 7;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 7:
                                    right--;
                                    array[right] = 9;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 9:
                                    right--;
                                    array[right] = 11;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 11:
                                    right--;
                                    array[right] = 13;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 13:
                                    right--;
                                    array[right] = 15;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 15:
                                    right--;
                                    array[right] = 17;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 17:
                                    right--;
                                    array[right] = 19;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 19:
                                    right--;
                                    array[right] = 21;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << endl;
                                    break;
                                case 21:
                                    right--;
                                    array[right] = 23;
                                    cout << "Стек успешно увеличен. Добавлен элемент " << array[right] << ',';
                                    cout << " достигнут максимальный размер" << endl;
                                    break;
                                }
                            }
                            else
                            {
                                if (right == 0)
                                {
                                    cout << "Ошибка. Стек имеет максимальный размер. Массив полон" << endl;
                                }
                                else
                                {
                                    cout << "Ошибка. Пересечение с первым стеком, добавление элемента невозможно" << endl;
                                }
                            }
                        }

                        if (button == 2) // кнопка удаления
                        {
                            switch (array[right])
                            {
                            case 23:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 21:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 19:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 17:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 15:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 13:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 11:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 9:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 7:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 5:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 3:
                                cout << "Успешно удалена текущая вершина стека - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " Новая вершина стека - " << array[right] << endl;
                                break;
                            case 1:
                                cout << "Успешно удален единственный элемент стека - " << array[right] << '.';
                                array[right] = 0;
                                rightStart = false;
                                cout << " Стек пуст" << endl;
                                break;
                            case 0:
                                cout << "Ошибка, стек пуст" << endl;
                                break;
                            default:
                                cout << "Ошибка, стек пуст" << endl;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        }
    }
}