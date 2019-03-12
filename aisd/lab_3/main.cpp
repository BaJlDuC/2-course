#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#define DIGITS(x) (x >= 0 && x <= 9) // dont work

using namespace std;
const string ENTER_INPUT = "Enter name of input file(tree): ";
const string INPUT_NOT_OPEN = "Input file is not open. Check file name correctness";
const string INPUT_OPEN = "Input file is open\n";
const string ROOT_FIND = "Root find";
const string ROOT_NOT_FIND = "Don't find a root. Root begin without '*' and with\na capital letter";
const string TOTAL_WEIGHT = "Total weight = ";
const string CHANGE_VALUES = "Do you want to change vertex values? Y - yes, N - no, exit\n";
const string ENTER_VERTEX = "Enter vertex of tree (value of vertex != 0): ";
const string VERTEX_ERROR = "Error. Vertex value can not be a 0 or vertex does not exist\n";
const string SELECTED_VERTEX = "Selected vertex ";
const string CURRENT_VALUE = ". Current value ";
const string NEW_VALUE = "Enter new value: ";
const string ERROR_VALUE = "Error. Enter only numbers";
const string NEW_WEIGHT = "New total weight = ";
const string UNKNOWN_COMMAND = "Unknown command. Press Y to change size of voliages\nor press N to exit\n";

bool digitNumber(int x)
{
    if ((x >= '0') && (x <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string inputFile;
    string treeLine;

    int allMass = 0;
    int mass = 0;
    int moveNumber = 0;
    int newValue = 0;
    bool findRoot = false;
    bool errorNum = false;
    char treeVertex;
    char button = '0';
    map<char, int> foliage;

    cout << ENTER_INPUT << endl;
    cin >> inputFile;
    ifstream inputTree(inputFile.c_str());
    if (!inputTree)
    {
        cout << INPUT_NOT_OPEN << endl;
        return 1;
    }
    else
    {
        cout << INPUT_OPEN
             << endl;
    }

    while (!inputTree.eof())
    {
        moveNumber = 0;
        inputTree >> treeLine;
        for (int i = 0; i < treeLine.size(); i++)
        {
            if (findRoot == false)
            {
                if ((treeLine[i] <= 'Z') && (treeLine[i] >= 'A'))
                {
                    cout << ROOT_FIND << endl;
                    findRoot = true;
                }
                else
                {
                    cout << ROOT_NOT_FIND << endl;
                    return 1;
                }
            }

            if ((treeLine[i] == '*') || treeLine[i] == ('-'))
            {
                treeLine[i] = 0;
            }

            if ((treeLine[i] <= 'Z') && (treeLine[i] >= 'A'))
            {
                foliage[treeLine[i]] = 0;
                treeVertex = treeLine[i];
                treeLine[i] = 0;
            }

            if ((treeLine[i] <= '9') && (treeLine[i] >= '0'))
            {
                treeLine[moveNumber++] = treeLine[i];
                treeLine[i] = 0;
            }
        }
        stringstream convertString;
        convertString << treeLine;
        convertString >> mass;
        foliage[treeVertex] = mass;
        allMass += mass;
    }
    map<char, int>::iterator it = foliage.begin();
    cout << TOTAL_WEIGHT << allMass << endl;

    while (button != 'N')
    {
        cout << CHANGE_VALUES
             << endl;
        cin >> button;
        if (button == 'Y')
        {
            cout << ENTER_VERTEX << endl;
            cin >> button;
            map<char, int>::iterator it_find, it_notFind;

            if (foliage[button] == 0)
            {
                cout << VERTEX_ERROR
                     << endl;
            }
            else
            {

                it_find = foliage.find(button);
                cout << SELECTED_VERTEX << button << CURRENT_VALUE << it_find->second << endl;
                cout << NEW_VALUE << endl;
                allMass -= foliage[button];
                cin >> treeLine;
                errorNum = false;
                for (int i = 0; i < treeLine.size(); i++)
                {
                    if (errorNum == false)
                    {

                        if (!digitNumber(treeLine[i]))
                        {
                            cout << ERROR_VALUE << endl;
                            errorNum = true;
                        }
                    }
                }
                if (errorNum == false)
                {
                    stringstream convertString;
                    convertString << treeLine;
                    convertString >> newValue;

                    foliage[button] = newValue;
                    allMass += newValue;
                    cout << NEW_WEIGHT << allMass << endl;
                }
            }
        }
        else if (button != 'N')
        {
            cout << UNKNOWN_COMMAND
                 << endl;
        }
    }
}