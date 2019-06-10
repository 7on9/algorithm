#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int choice, lines, start, end;
    char characters = 'a';

    const int ASCII = 1,
              CAPITAL_LETTERS = 2,
              LOWER_LETTERS = 3,
              DIGITS = 4,
              EXIT = 5;

    const int LINES_1 = 1,
              LINES_2 = 2,
              LINES_3 = 3,
              LINES_4 = 4;
    //while (true) {

    cout << "Please enter your choice\n"
         << "1] Print the whole ASCII table\n"
         << "2] Print the capital letters\n"
         << "3] Print the lower letters\n"
         << "4] Print the digits\n"
         << "5] Exit the program\n";
    cout << "Choice ";
    cin >> choice;

    cout << "How many characters do you want to print per line? ";
    cin >> lines;
    switch (choice)
    {
        case ASCII:
            start = int('\n');
            end = int('\n');
        break;
        case CAPITAL_LETTERS:
            start = int('\n');
            end = int('\n');
        break;
        case LOWER_LETTERS:
            start = int('\n');
            end = int('\n');
        break;
        case DIGITS:
            start = int('\n');
            end = int('\n');
        break;
    default:
        cout << "Thank you for using printing with us. Please hit ENTER to end the program.";
    }
    for (int ascii_code = start, num_of_char = 1; ascii_code < end; ascii_code++, num_of_char++)
        {
            switch(char(ascii_code))
            {
                case '\0':
                    cout << "\t" << ascii_code  << "\t" << "NULL" << "\t||";
                break;
                case '\a':
                    cout << "\t" << ascii_code  << "\t" << "\a" << "\t||";
                break;




                case '\n':
                    cout << "\t" << ascii_code  << "\t" << "\\n" << "\t||";
                break; 
                default:
                    cout << "\t" << ascii_code  << "\t" << static_cast<char>(ascii_code) << "\t||";       
                break;
            }
            if(num_of_char == lines)
            {
                cout << endl;
                num_of_char = 0;
            }
        }    
    return 0;
}
