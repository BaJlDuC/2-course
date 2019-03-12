#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RUSSIAN");

    char buff[15];
    char counter_buff[15];
    int counter = 1;
    int main_position = 0;
    int position = 1;
    int first_space = 1;
    int no_space = 0;
    int word_counter = 0;
    int word_count_for_find = 0;
    int count = 0;

    BOOL end = FALSE;
    BOOL find_word = FALSE;
    BOOL in_open = FALSE;
    BOOL out_open = FALSE;
    BOOL dic_open = FALSE;

    string ifile;
    string ofile;
    string dic_file;

    cout << "Enter name of input file: " << endl;
    cin >> ifile;
    ifstream input_file(ifile.c_str());
    cout << "Enter name of output file: " << endl;
    cin >> ofile;
    ofstream output_file(ofile.c_str());
    cout << "Enter name of dictionary file: " << endl;
    cin >> dic_file;
    ofstream dictionary(dic_file.c_str());

    if (!input_file)
    {
        cout << "\nInput file is not open" << endl;
    }
    else
    {
        cout << "\nInput file is open" << endl;
        in_open = TRUE;
    }
    if (!output_file)
    {
        cout << "Output file is not open" << endl;
    }
    else
    {
        cout << "Output file is open" << endl;
        out_open = TRUE;
    }
    if (!dictionary)
    {
        cout << "Dictionary file is not open" << endl;
    }
    else
    {
        cout << "Dictionary file is open" << endl;
        dic_open = TRUE;
    }
    if (in_open == TRUE && out_open == TRUE && dic_open == TRUE)
    {
        while (!input_file.eof())
        {
            input_file >> buff;
            word_counter++;
            for (int indx = 0; indx < 15; indx++)
            {
                if (buff[indx] == '-')
                {
                    no_space = word_counter + 1;
                }
            }
            if ((word_counter > 1) && (no_space != word_counter))
            {
                dictionary << ' ' << buff;
            }
            else
            {
                dictionary << buff;
            }
        }
        input_file.close();
        dictionary.close();
        ifstream dictionary(dic_file.c_str());
        word_counter = 0;
        while (!dictionary.eof())
        {
            dictionary >> buff;
            word_counter++;
            first_space = 0;
            position = 1;
            count = 0;
            for (int i = 0; i < 15; i++)
            {
                if (buff[i] == ',' ||
                    buff[i] == '.' ||
                    buff[i] == ';' ||
                    buff[i] == '!' ||
                    buff[i] == '?' ||
                    buff[i] == ':')
                {
                    buff[i] = 0;
                    first_space = 1;
                }
                if (buff[i] == '-')
                {
                    while (buff[i + count] != 0)
                    {
                        buff[i + count] = buff[i + count + 1];
                        count++;
                    }
                }
                switch (buff[i])
                {
                case 'A':
                    buff[i] = 'a';
                    break;
                case 'B':
                    buff[i] = 'b';
                    break;
                case 'C':
                    buff[i] = 'c';
                    break;
                case 'D':
                    buff[i] = 'd';
                    break;
                case 'E':
                    buff[i] = 'e';
                    break;
                case 'F':
                    buff[i] = 'f';
                    break;
                case 'G':
                    buff[i] = 'f';
                    break;
                case 'H':
                    buff[i] = 'h';
                    break;
                case 'I':
                    buff[i] = 'i';
                    break;
                case 'J':
                    buff[i] = 'j';
                    break;
                case 'K':
                    buff[i] = 'k';
                    break;
                case 'L':
                    buff[i] = 'l';
                    break;
                case 'M':
                    buff[i] = 'm';
                    break;
                case 'N':
                    buff[i] = 'n';
                    break;
                case 'O':
                    buff[i] = 'o';
                    break;
                case 'P':
                    buff[i] = 'p';
                    break;
                case 'Q':
                    buff[i] = 'q';
                    break;
                case 'R':
                    buff[i] = 'r';
                    break;
                case 'S':
                    buff[i] = 's';
                    break;
                case 'T':
                    buff[i] = 't';
                    break;
                case 'U':
                    buff[i] = 'u';
                    break;
                case 'V':
                    buff[i] = 'v';
                    break;
                case 'W':
                    buff[i] = 'w';
                    break;
                case 'X':
                    buff[i] = 'x';
                    break;
                case 'Y':
                    buff[i] = 'y';
                    break;
                case 'Z':
                    buff[i] = 'z';
                    break;
                }
                // rus
                switch (buff[i])
                {
                case 'À':
                    buff[i] = 'à';
                    break;
                case 'Á':
                    buff[i] = 'á';
                    break;
                case 'Â':
                    buff[i] = 'â';
                    break;
                case 'Ã':
                    buff[i] = 'ã';
                    break;
                case 'Ä':
                    buff[i] = 'ä';
                    break;
                case 'Å':
                    buff[i] = 'å';
                    break;
                case '¨':
                    buff[i] = '¸';
                    break;
                case 'Æ':
                    buff[i] = 'æ';
                    break;
                case 'Ç':
                    buff[i] = 'ç';
                    break;
                case 'È':
                    buff[i] = 'è';
                    break;
                case 'Ê':
                    buff[i] = 'ê';
                    break;
                case 'Ë':
                    buff[i] = 'ë';
                    break;
                case 'Ì':
                    buff[i] = 'ì';
                    break;
                case 'Í':
                    buff[i] = 'í';
                    break;
                case 'Î':
                    buff[i] = 'î';
                    break;
                case 'Ï':
                    buff[i] = 'ï';
                    break;
                case 'Ð':
                    buff[i] = 'ð';
                    break;
                case 'Ñ':
                    buff[i] = 'ñ';
                    break;
                case 'Ò':
                    buff[i] = 'ò';
                    break;
                case 'Ó':
                    buff[i] = 'ó';
                    break;
                case 'Ô':
                    buff[i] = 'ô';
                    break;
                case 'Õ':
                    buff[i] = 'õ';
                    break;
                case 'Ö':
                    buff[i] = 'ö';
                    break;
                case '×':
                    buff[i] = '÷';
                    break;
                case 'Ø':
                    buff[i] = 'ø';
                    break;
                case 'Ù':
                    buff[i] = 'ù';
                    break;
                case 'Ú':
                    buff[i] = 'ú';
                    break;
                case 'Û':
                    buff[i] = 'û';
                    break;
                case 'Ü':
                    buff[i] = 'ü';
                    break;
                case 'Ý':
                    buff[i] = 'ý';
                    break;
                case 'Þ':
                    buff[i] = 'þ';
                    break;
                case 'ß':
                    buff[i] = 'ÿ';
                    break;
                }
                if ((buff[i] == 0) && (position == 1))
                {
                    position = i + 1 + first_space;
                }
            }
            main_position = main_position + position;
            if (dictionary.eof())
            {
                end = TRUE;
            }
            while (!dictionary.eof())
            {
                dictionary >> counter_buff;
                count = 0;
                for (int ic = 0; ic < 15; ic++)
                {
                    if (counter_buff[ic] == ',' ||
                        counter_buff[ic] == '.' ||
                        counter_buff[ic] == ';' ||
                        counter_buff[ic] == '!' ||
                        counter_buff[ic] == '?' ||
                        counter_buff[ic] == ':')
                    {
                        counter_buff[ic] = 0;
                    }
                    if (counter_buff[ic] == '-')
                    {
                        while (counter_buff[ic + count] != 0)
                        {
                            counter_buff[ic + count] = counter_buff[ic + count + 1];
                            count++;
                        }
                    }
                    switch (counter_buff[ic])
                    {
                    case 'A':
                        counter_buff[ic] = 'a';
                        break;
                    case 'B':
                        counter_buff[ic] = 'b';
                        break;
                    case 'C':
                        counter_buff[ic] = 'c';
                        break;
                    case 'D':
                        counter_buff[ic] = 'd';
                        break;
                    case 'E':
                        counter_buff[ic] = 'e';
                        break;
                    case 'F':
                        counter_buff[ic] = 'f';
                        break;
                    case 'G':
                        counter_buff[ic] = 'f';
                        break;
                    case 'H':
                        counter_buff[ic] = 'h';
                        break;
                    case 'I':
                        counter_buff[ic] = 'i';
                        break;
                    case 'J':
                        counter_buff[ic] = 'j';
                        break;
                    case 'K':
                        counter_buff[ic] = 'k';
                        break;
                    case 'L':
                        counter_buff[ic] = 'l';
                        break;
                    case 'M':
                        counter_buff[ic] = 'm';
                        break;
                    case 'N':
                        counter_buff[ic] = 'n';
                        break;
                    case 'O':
                        counter_buff[ic] = 'o';
                        break;
                    case 'P':
                        counter_buff[ic] = 'p';
                        break;
                    case 'Q':
                        counter_buff[ic] = 'q';
                        break;
                    case 'R':
                        counter_buff[ic] = 'r';
                        break;
                    case 'S':
                        counter_buff[ic] = 's';
                        break;
                    case 'T':
                        counter_buff[ic] = 't';
                        break;
                    case 'U':
                        counter_buff[ic] = 'u';
                        break;
                    case 'V':
                        counter_buff[ic] = 'v';
                        break;
                    case 'W':
                        counter_buff[ic] = 'w';
                        break;
                    case 'X':
                        counter_buff[ic] = 'x';
                        break;
                    case 'Y':
                        counter_buff[ic] = 'y';
                        break;
                    case 'Z':
                        counter_buff[ic] = 'z';
                        break;
                    }
                    //rus
                    switch (counter_buff[ic])
                    {
                    case 'À':
                        counter_buff[ic] = 'à';
                        break;
                    case 'Á':
                        counter_buff[ic] = 'á';
                        break;
                    case 'Â':
                        counter_buff[ic] = 'â';
                        break;
                    case 'Ã':
                        counter_buff[ic] = 'ã';
                        break;
                    case 'Ä':
                        counter_buff[ic] = 'ä';
                        break;
                    case 'Å':
                        counter_buff[ic] = 'å';
                        break;
                    case '¨':
                        counter_buff[ic] = '¸';
                        break;
                    case 'Æ':
                        counter_buff[ic] = 'æ';
                        break;
                    case 'Ç':
                        counter_buff[ic] = 'ç';
                        break;
                    case 'È':
                        counter_buff[ic] = 'è';
                        break;
                    case 'Ê':
                        counter_buff[ic] = 'ê';
                        break;
                    case 'Ë':
                        counter_buff[ic] = 'ë';
                        break;
                    case 'Ì':
                        counter_buff[ic] = 'ì';
                        break;
                    case 'Í':
                        counter_buff[ic] = 'í';
                        break;
                    case 'Î':
                        counter_buff[ic] = 'î';
                        break;
                    case 'Ï':
                        counter_buff[ic] = 'ï';
                        break;
                    case 'Ð':
                        counter_buff[ic] = 'ð';
                        break;
                    case 'Ñ':
                        counter_buff[ic] = 'ñ';
                        break;
                    case 'Ò':
                        counter_buff[ic] = 'ò';
                        break;
                    case 'Ó':
                        counter_buff[ic] = 'ó';
                        break;
                    case 'Ô':
                        counter_buff[ic] = 'ô';
                        break;
                    case 'Õ':
                        counter_buff[ic] = 'õ';
                        break;
                    case 'Ö':
                        counter_buff[ic] = 'ö';
                        break;
                    case '×':
                        counter_buff[ic] = '÷';
                        break;
                    case 'Ø':
                        counter_buff[ic] = 'ø';
                        break;
                    case 'Ù':
                        counter_buff[ic] = 'ù';
                        break;
                    case 'Ú':
                        counter_buff[ic] = 'ú';
                        break;
                    case 'Û':
                        counter_buff[ic] = 'û';
                        break;
                    case 'Ü':
                        counter_buff[ic] = 'ü';
                        break;
                    case 'Ý':
                        counter_buff[ic] = 'ý';
                        break;
                    case 'Þ':
                        counter_buff[ic] = 'þ';
                        break;
                    case 'ß':
                        counter_buff[ic] = 'ÿ';
                        break;
                    }
                }
                if (strcmp(buff, counter_buff) == 0)
                {
                    counter++;
                }
            }

            dictionary.seekg(0, ios::beg);
            word_count_for_find = 0;
            find_word = FALSE;
            while ((word_count_for_find) != (word_counter - 1))
            {
                dictionary >> counter_buff;
                word_count_for_find++;
                count = 0;
                for (int index = 0; index < 15; index++)
                {
                    if (counter_buff[index] == ',' ||
                        counter_buff[index] == '.' ||
                        counter_buff[index] == ';' ||
                        counter_buff[index] == '!' ||
                        counter_buff[index] == '?' ||
                        counter_buff[index] == ':')
                    {
                        counter_buff[index] = 0;
                    }
                    if (counter_buff[index] == '-')
                    {
                        while (counter_buff[index + count] != 0)
                        {
                            counter_buff[index + count] = counter_buff[index + count + 1];
                            count++;
                        }
                    }
                    switch (counter_buff[index])
                    {
                    case 'A':
                        counter_buff[index] = 'a';
                        break;
                    case 'B':
                        counter_buff[index] = 'b';
                        break;
                    case 'C':
                        counter_buff[index] = 'c';
                        break;
                    case 'D':
                        counter_buff[index] = 'd';
                        break;
                    case 'E':
                        counter_buff[index] = 'e';
                        break;
                    case 'F':
                        counter_buff[index] = 'f';
                        break;
                    case 'G':
                        counter_buff[index] = 'f';
                        break;
                    case 'H':
                        counter_buff[index] = 'h';
                        break;
                    case 'I':
                        counter_buff[index] = 'i';
                        break;
                    case 'J':
                        counter_buff[index] = 'j';
                        break;
                    case 'K':
                        counter_buff[index] = 'k';
                        break;
                    case 'L':
                        counter_buff[index] = 'l';
                        break;
                    case 'M':
                        counter_buff[index] = 'm';
                        break;
                    case 'N':
                        counter_buff[index] = 'n';
                        break;
                    case 'O':
                        counter_buff[index] = 'o';
                        break;
                    case 'P':
                        counter_buff[index] = 'p';
                        break;
                    case 'Q':
                        counter_buff[index] = 'q';
                        break;
                    case 'R':
                        counter_buff[index] = 'r';
                        break;
                    case 'S':
                        counter_buff[index] = 's';
                        break;
                    case 'T':
                        counter_buff[index] = 't';
                        break;
                    case 'U':
                        counter_buff[index] = 'u';
                        break;
                    case 'V':
                        counter_buff[index] = 'v';
                        break;
                    case 'W':
                        counter_buff[index] = 'w';
                        break;
                    case 'X':
                        counter_buff[index] = 'x';
                        break;
                    case 'Y':
                        counter_buff[index] = 'y';
                        break;
                    case 'Z':
                        counter_buff[index] = 'z';
                        break;
                    }
                    //rus
                    switch (counter_buff[index])
                    {
                    case 'À':
                        counter_buff[index] = 'à';
                        break;
                    case 'Á':
                        counter_buff[index] = 'á';
                        break;
                    case 'Â':
                        counter_buff[index] = 'â';
                        break;
                    case 'Ã':
                        counter_buff[index] = 'ã';
                        break;
                    case 'Ä':
                        counter_buff[index] = 'ä';
                        break;
                    case 'Å':
                        counter_buff[index] = 'å';
                        break;
                    case '¨':
                        counter_buff[index] = '¸';
                        break;
                    case 'Æ':
                        counter_buff[index] = 'æ';
                        break;
                    case 'Ç':
                        counter_buff[index] = 'ç';
                        break;
                    case 'È':
                        counter_buff[index] = 'è';
                        break;
                    case 'Ê':
                        counter_buff[index] = 'ê';
                        break;
                    case 'Ë':
                        counter_buff[index] = 'ë';
                        break;
                    case 'Ì':
                        counter_buff[index] = 'ì';
                        break;
                    case 'Í':
                        counter_buff[index] = 'í';
                        break;
                    case 'Î':
                        counter_buff[index] = 'î';
                        break;
                    case 'Ï':
                        counter_buff[index] = 'ï';
                        break;
                    case 'Ð':
                        counter_buff[index] = 'ð';
                        break;
                    case 'Ñ':
                        counter_buff[index] = 'ñ';
                        break;
                    case 'Ò':
                        counter_buff[index] = 'ò';
                        break;
                    case 'Ó':
                        counter_buff[index] = 'ó';
                        break;
                    case 'Ô':
                        counter_buff[index] = 'ô';
                        break;
                    case 'Õ':
                        counter_buff[index] = 'õ';
                        break;
                    case 'Ö':
                        counter_buff[index] = 'ö';
                        break;
                    case '×':
                        counter_buff[index] = '÷';
                        break;
                    case 'Ø':
                        counter_buff[index] = 'ø';
                        break;
                    case 'Ù':
                        counter_buff[index] = 'ù';
                        break;
                    case 'Ú':
                        counter_buff[index] = 'ú';
                        break;
                    case 'Û':
                        counter_buff[index] = 'û';
                        break;
                    case 'Ü':
                        counter_buff[index] = 'ü';
                        break;
                    case 'Ý':
                        counter_buff[index] = 'ý';
                        break;
                    case 'Þ':
                        counter_buff[index] = 'þ';
                        break;
                    case 'ß':
                        counter_buff[index] = 'ÿ';
                        break;
                    }
                }
                if (strcmp(buff, counter_buff) == 0)
                {
                    counter++;
                    if (find_word == FALSE)
                    {
                        find_word = TRUE;
                    }
                }
            }
            if ((buff[0] != 0) && (find_word == FALSE))
            {
                output_file << buff << "  " << counter << endl;
            }
            if (end == FALSE)
            {
                dictionary.seekg(main_position, ios::beg);
            }
            counter = 1;
        }
    }
    input_file.close();
    output_file.close();
    dictionary.close();
}
