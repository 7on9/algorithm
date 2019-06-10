//Print the WHOLE ASCII Table or the Alphabet n characters per line using for loop
//Print the WHOLE ASCII Table or the Alphabet n characters per line
//Programmer: Nhu Nguyen
//Date: 3/6/18


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

	system("title Print the WHOLE ASCII Table or the Alphabet n characters per line by Nhu Nguyen");
	system("color 4e");

	//Describe the lab
	cout << "                          Print the WHOLE ASCII table or the Alphabet\n"
		<< "                                     n characters per line            \n"
		<< "                                      By Nhu Nguyen";

	do {
		cout << "\n\n\nPlease enter your choice:\n"
			<< "         1] Print the whole ASCII table\n"
			<< "         2] Print the capital letters\n"
			<< "         3] Print the lower letters\n"
			<< "         4] print the digits\n"
			<< "         5] Exit the program\n"
			<< "Choice: ";
		cin >> choice;
		if (choice < 1 || choice > 5)
		{
			cout << "\n ***Invalid choice.";
			cout << "\a" << endl;
		}
		switch (choice)
		{
		case ASCII:
			start = 0;
			end = 255;
			break;
		case CAPITAL_LETTERS:
			start = int('A');
			end = int('Z');
			break;
		case LOWER_LETTERS:
			start = int('a');
			end = int('z');
			break;
		case DIGITS:
			start = int('0');
			end = int('9');
			break;
		default:
			cout << "Thank you for using printing with us.\n";
            char ch;
            cin.ignore(1);
            cin.get(ch);
            return 0;
		}
		cout << endl;
		cout << "How many characters do you want to print per line? ";
		cin >> lines;
		for (int ascii_code = start, num_of_char = 1; ascii_code <= end; ascii_code++)
		{
			switch (char(ascii_code))
			{
			case '\0':
				cout << ascii_code<< "\tNULL\t";
				break;
			case '\a':
				cout << ascii_code << "\t\\a\t";
				break;
			case '\n':
				cout << ascii_code << "\t\\n\t";
				break;
			case'\b':
				cout << ascii_code << "\t\\b\t";
				break;
			case'\v':
				cout << ascii_code << "\t\\v\t";
				break;
			case'\r':
				cout << ascii_code << "\t\\r\t";
				break;
			case'\t':
				cout << ascii_code << "\t\\t\t";
				break;
			default:
				cout << ascii_code << "\t" << static_cast<char>(ascii_code) <<"\t";
				break;
			}
            num_of_char++;
			if (num_of_char > lines)
			{
				cout << endl;
				num_of_char = 1;
			}
			else
				cout << "||\t";

		}
	} while (choice != EXIT);
		
	
	return 0;
}


