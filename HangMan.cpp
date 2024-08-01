#include <iostream>
#include <ctime>
using namespace std;

int life = 3; // Global declaration for number of chances
string message = "You Have 3 Chances!!";

void hangMan(char);
int checkGuess(char, string, string &);

int main()
{
    system("cls");
    char userLetter; // input charater from the user
    string month;    // Guess month by the user
    string months[] = {
        "january",
        "february",
        "march",
        "may",
        "june",
        "july",
        "august",
        "september",
        "october",
        "november",
        "december"};

    srand(time(NULL));
    int month_number = rand() % 12; // Randomly Genrates index number of month.
    month = months[month_number];

    string hide_month(month.length(), 'X'); // here it will hide the months charater by 'X'.

    system("cls");

    while (life != 0)
    {
        hangMan('n'); // Neutral state of HungMan..
        cout << "\t\t\t\tLife: " << life << endl;
        cout << "\t\t\t\t" << hide_month << endl;
        cout << "\t\t\t\tGuess the Letter: ";
        cin >> userLetter;

        system("cls");
        if (checkGuess(userLetter, month, hide_month) == 0)
        {
            message = "Incorrect Letter! "; // if user input is not matching with any of the letter with the given random month then it will print this state statement.
            life--;
        }
        else
        {
            message = "Great!! Correct Guess";
        }

        if (hide_month == month)
        {
            message = "You're Free to GO!!";
            hangMan('f'); // for free statement
            cout << "\t\t\t\tLife: " << life << endl;
            cout << "\t\t\tThe month is: " << month << endl;
            break;
        }
    }

    if (life == 0)
    {
        message = "You're Hanged!!";
        hangMan('h'); // for Hanged state.
        cout << "\t\t\t\tLife: " << life << endl;
        cout << "\t\t\tThe month is: " << month << endl;
    }

    return 0;
};

int checkGuess(char guess, string real_month, string &hidden_month) // guess: user guessed letter.
{                                                                   // real_month: the month which should be guessed by the user.
    int matches = 0;                                                // to check how many letters has been match with the actual month
    int len = real_month.length();                                  // for limitting the lenth of the for loop.
    for (int i = 0; i < len; i++)
    {
        if (guess == hidden_month[i]) // if player gives the wrong input then life/chance of the player will get decerease.
        {
            return 0;
        }
        if (guess == real_month[i]) // here it will reveal the month
        {
            hidden_month[i] = guess;
            matches++;
        }
    }
    return matches;
}

void hangMan(char state)
{
    string hangMan_rope = "|";
    if (state == 'f')
    {
        hangMan_rope = " ";
    }

    string hangMan_ground = "=====";
    if (state == 'h')
    {
        hangMan_ground = "     ";
    }

    string Executioner = "\\";
    if (state == 'h')
    {
        Executioner = " /";
    }

    cout << "\t\t\t\t___________________________" << endl;
    cout << "\t\t\t\t              " << hangMan_rope << "          |" << endl;
    cout << "\t\t\t\t              O          |" << endl;
    cout << "\t\t\t\t             / \\         |" << "\t          " << message << endl;
    cout << "\t\t\t\t              |          |" << "\t         /" << endl;
    cout << "\t\t\t\t             / \\         |              O   " << endl;
    cout << "\t\t\t\t          ==" << hangMan_ground << "==      |             / \\" << endl;
    cout << "\t\t\t\t          |       |      |        " << Executioner << "    |" << endl;
    cout << "\t\t\t\t          |       |      |        ==   / \\" << endl;
    cout << "\t\t\t\t=================================|==|=================" << endl;
}
