#include <iostream>
#include <fstream>
#include <cstdlib>
// Çàãîëîâî÷íûå ôàéëû äëÿ ôàéëîâîãî ââîäà-âûâîäà

#include <conio.h>   //íåîáõîäèìî äëÿ getch()

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");

/*ñîçäàåì îáúåêò F1, êîòîðûé ñîçäàñò ôàéë file.txt
öèêëîì for çàïîëíåÿåì ôàéë èç ìàññèâà x[10]] */
    cout << "Êàêîé äëèíû áóäåò îäíà ñòðîêà â ôàéëå: ";
    int k = 0;
    cin >> k;
    ofstream F1("file.txt", ios_base::trunc);
    for ( int i = 0; i < 15; i++) {
        for ( int j = 0; j < k; j++) {
            F1 << rand() % 10;
        }
        F1 << "\n";
    }
    F1.close();

    cout << "Ââåäèòå íîìåð ñòðîêè, êîòîðóþ íóæíî âûâåñòè (1-15): ";
    int n = 0;
    cin >> n;
    ifstream file("file.txt");

    if (n > 1)
        file.seekg((n - 1) * (k + 2));
    else
        file.seekg(0);
    char str[k]; // áóôåð äëÿ ÷òåíèÿ îäíîé ñòðîêè
    file.getline (str, k + 1);
    cout << "Ñòðîêà ¹" << n << ": " << str << endl;
    file.close();
    return 0;
}
