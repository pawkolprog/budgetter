#include <iostream>

#include "budgetter.h"
#include "auxiliaryMethods.h"

using namespace std;

char chooseOptionsFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

char chooseOptionsFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. View current month balance" << endl;
    cout << "4. View last month balance" << endl;
    cout << "5. View balance for given dates" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

int main()
{
    Budgetter budgetter("incomes.xml", "expenses.xml", "users.xml");
    char choice;

    while (true)
    {
        if (budgetter.getLoggedInUserId() == 0)
        {
            choice = chooseOptionsFromMainMenu();

            switch (choice)
            {
            case '1':
                //ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                //ksiazkaAdresowa.zalogujUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = chooseOptionsFromUserMenu();

            switch (choice)
            {
            case '1':
                //ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                //ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            default:
                cout << endl << "There is no such option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
