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
        cout << "1. ��������� �������" << endl;
        cout << "2. ������� ����" << endl;
        cout << "9. �����" << endl;
        cout << endl;
        cin >> button;
        cout << endl;
        switch (button)
        {
        case 1:
            cout << "������ �� ������� ������: ";
            for (int i = 0; i <= 11; i++) //!= 12
            {
                cout << array[i] << ' '; // ����� ��������� �������
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
                    cout << " ������� ������ ���� ��������� ������: " << freeIndexStart << endl;
                }
                else
                {
                    cout << "�������� ��������� ��������: [" << freeIndexStart << "; " << freeIndexEnd << "] " << endl;
                }
            }
            else
            {
                cout << "��������� �������� �� �������� " << endl;
            }

            if ((array[left] != 0) && (leftStart == true))
            {
                cout << "����1(�����, ����� � �������� �������): ";
                while (leftArray >= 0)
                {
                    cout << array[leftArray] << ' ';
                    leftArray--;
                }
                cout << endl;
            }
            else
            {
                cout << "����1(�����) ����" << endl;
            }

            if ((array[right] != 0) && (rightStart == true))
            {
                cout << "����2(������, ����� � �������� �������): ";
                while (rightArray != 12)
                {
                    cout << array[rightArray] << ' ';
                    rightArray++;
                }
                cout << endl;
            }
            else
            {
                cout << "����2(������) ����" << endl;
            }
            break;
        case 2:
            cout << "     �������� ����" << endl;
            while (button != 3)
            {
                cout << "1. ����1(�����)" << endl;
                cout << "2. ����2(������)" << endl;
                cout << "3. ���������" << endl;
                cout << endl;

                cin >> button;
                cout << endl;
                if (button == 1) // ����� ������� � �������
                {
                    while (button != 4)
                    {
                        cout << "     ������ ����1(�����)" << endl;
                        cout << "1. �������� �������" << endl;
                        cout << "2. ������� �������" << endl;
                        cout << "3. ������� �� ����� �������� �����" << endl;
                        cout << "4. �����" << endl;
                        cout << endl;

                        cin >> button;
                        cout << endl;
                        if (button == 3) //������ ������ ���������
                        {
                            leftArray = left;
                            if ((array[left] != 0) && (leftStart == true))
                            {
                                cout << "�������� ���������� �����: ";
                                while (leftArray >= 0)
                                {
                                    cout << array[leftArray] << ' ';
                                    leftArray--;
                                }
                            }
                            else
                            {
                                cout << "��������� ���� ����" << endl;
                            }
                            cout << endl;
                        }

                        if (button == 1) // ������ ���������� �������� � ����
                        {
                            if ((array[left + 1] == 0) || (array[left] == 0)) // ���� ��� ||
                            {
                                switch (array[left]) //���������� ������� ������� �������
                                {
                                case 0:
                                    array[left] = 2;
                                    leftStart = true;
                                    cout << "���� ������� ��������. �������� ������ ������� " << array[left] << endl;
                                    break;
                                case 2:
                                    array[left + 1] = 4;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 4:
                                    array[left + 1] = 6;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 6:
                                    array[left + 1] = 8;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 8:
                                    array[left + 1] = 10;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 10:
                                    array[left + 1] = 12;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 12:
                                    array[left + 1] = 14;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 14:
                                    array[left + 1] = 16;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 16:
                                    array[left + 1] = 18;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 18:
                                    array[left + 1] = 20;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 20:
                                    array[left + 1] = 22;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << endl;
                                    break;
                                case 22:
                                    array[left + 1] = 24;
                                    left++;
                                    cout << "���� ������� ��������. �������� ������� " << array[left] << ',';
                                    cout << " ��������� ������������ ������" << endl;
                                    break;
                                case 24: // �� �����
                                    cout << "������. ���� ����� ������������ ������. ������ �����." << endl;
                                    break;
                                }
                            }
                            else
                            {
                                if (left == 11)
                                {
                                    cout << "������. ���� ����� ������������ ������. ������ �����" << endl;
                                }
                                else
                                {
                                    cout << "������. ����������� �� ������ ������, ���������� �������� ����������" << endl;
                                }
                            }
                        }

                        if (button == 2) // ������ �������� ��������
                        {
                            switch (array[left])
                            {
                            case 24:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 22:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 20:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 18:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 16:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 14:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 12:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 10:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 8:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 6:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 4:
                                cout << "������� ������� ������� ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                left--;
                                cout << " ����� ������� ����� - " << array[left] << endl;
                                break;
                            case 2:
                                cout << "������� ������ ������������ ������� ����� - " << array[left] << '.';
                                array[left] = 0;
                                leftStart = false;
                                cout << " � ����� �� �������� ���������" << endl;
                                break;
                            case 0:
                                cout << "������, ���� ����" << endl;
                                break;
                            default:
                                cout << "������, ���� ����" << endl;
                                break;
                            }
                        }
                    }
                }

                if (button == 2)
                {
                    while (button != 4)
                    {
                        cout << "     ������ ����2(������)" << endl;
                        cout << "1. �������� �������" << endl;
                        cout << "2. ������� �������" << endl;
                        cout << "3. ������� �� ����� �������� �����" << endl;
                        cout << "4. �����" << endl;
                        cout << endl;

                        cin >> button;

                        cout << endl;
                        if (button == 3) // ������ ������ �� ����� ��������� �����
                        {
                            rightArray = right;
                            if ((array[right] != 0) && (rightStart == true))
                            {
                                cout << "�������� ���������� �����: ";
                                while (rightArray != 12)
                                {
                                    cout << array[rightArray] << ' ';
                                    rightArray++;
                                }
                                cout << endl;
                            }
                            else
                            {
                                cout << "��������� ���� ����" << endl;
                            }
                        }

                        if (button == 1) // ������ ���������� ��������
                        {
                            if ((array[right - 1] == 0) || (array[right] == 0))
                            {
                                switch (array[right])
                                {
                                case 0:
                                    array[right] = 1;
                                    cout << "���� ������� ��������. �������� ������ ������� " << array[right] << endl;
                                    rightStart = true;
                                    break;
                                case 1:
                                    right--;
                                    array[right] = 3;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 3:
                                    right--;
                                    array[right] = 5;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 5:
                                    right--;
                                    array[right] = 7;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 7:
                                    right--;
                                    array[right] = 9;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 9:
                                    right--;
                                    array[right] = 11;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 11:
                                    right--;
                                    array[right] = 13;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 13:
                                    right--;
                                    array[right] = 15;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 15:
                                    right--;
                                    array[right] = 17;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 17:
                                    right--;
                                    array[right] = 19;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 19:
                                    right--;
                                    array[right] = 21;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << endl;
                                    break;
                                case 21:
                                    right--;
                                    array[right] = 23;
                                    cout << "���� ������� ��������. �������� ������� " << array[right] << ',';
                                    cout << " ��������� ������������ ������" << endl;
                                    break;
                                }
                            }
                            else
                            {
                                if (right == 0)
                                {
                                    cout << "������. ���� ����� ������������ ������. ������ �����" << endl;
                                }
                                else
                                {
                                    cout << "������. ����������� � ������ ������, ���������� �������� ����������" << endl;
                                }
                            }
                        }

                        if (button == 2) // ������ ��������
                        {
                            switch (array[right])
                            {
                            case 23:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 21:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 19:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 17:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 15:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 13:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 11:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 9:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 7:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 5:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 3:
                                cout << "������� ������� ������� ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                right++;
                                cout << " ����� ������� ����� - " << array[right] << endl;
                                break;
                            case 1:
                                cout << "������� ������ ������������ ������� ����� - " << array[right] << '.';
                                array[right] = 0;
                                rightStart = false;
                                cout << " ���� ����" << endl;
                                break;
                            case 0:
                                cout << "������, ���� ����" << endl;
                                break;
                            default:
                                cout << "������, ���� ����" << endl;
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