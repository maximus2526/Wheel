// программа рулетка


#include <fstream>
#include <iostream>
#include <time.h>       /* time */
#include <string>
#include "windows.h"


using namespace std;


class Wheel {

public:
    //Wheel() {
    //    cout << "Создан обьект класа Wheel" << endl;
    //}
    int black = 1;
    int red = 2;
    int blue = 3;
    int gold = 4;
    int winner;

    int randomizer(){
       
        winner = 1+rand() % 2;
        return winner;
    }



    int coefficient() {
        int coefficient = 0;
        switch (winner)
        {
        case 1:
            coefficient = 2;
            break;
        case 2:
            coefficient = 3;
            break;
        case 3:
            coefficient = 5;
            break;
        case 4:
            coefficient = 50;
            break;
        default:
            cout << " Ошибка вычисления коофициента \n";
            break;
        }
        return coefficient;
    }

    ~Wheel()
    {
        cout << " Вызов диструктора Wheel\n";
    }

};

class Money : public Wheel {
     //Constructor
public:
    Money() {
        cout << "Создан обьект класа Money" << endl;
    }
    unsigned int current_balance = 1000;
    unsigned int bet_price;

    int enter_money() {
        cout << "Введите сколько поставить: \n";
        cin >> bet_price;
        return bet_price;
    }

    // Зменшився баланс
    int minus() {
        return current_balance = current_balance - bet_price;
    }
    // Збільшився баланс
    int plus() {
        return current_balance += bet_price * coefficient(); 
         
    }

    int betted_color() {
        string color_str;
        unsigned int betted_color;
        cout << "На который цвет поставить? \n";
        cin >> color_str;
        if (color_str == "black") {
            betted_color = black;
        }
        else if (color_str == "red")
        {
            betted_color = red;
        }
        //else if (color_str == "blue")
        //{
        //    betted_color = blue;
        //}
        //else if (color_str == "gold")
        //{
        //    betted_color = gold;
        //}
        else {
            betted_color = 0;
        }
        return betted_color;
    }


    int check_balance() {
        cout << "Баланс: " << current_balance << endl;
        return current_balance;
    }


    void bet_event() {
        enter_money();
        int pre_balance = current_balance;
        if (betted_color() == randomizer()) {
            minus();
            plus();
            cout << "-" << bet_price << " $ ";
            cout << "Рулетка крутится ! \n";
            int i = 0;
            while (i != 10) {
                Sleep(100);
                cout << " . ";
                i++;
            }
            cout << "\nВыпал (x" << coefficient() << ") : +" << current_balance - pre_balance << " $ ";
            check_balance();
        }
        else {
            minus();
            cout << "-" << bet_price << " $ ";
            cout << "Рулетка крутится ! \n";
            int i = 0;
            while (i != 10) {
                Sleep(100);
                cout << " . ";
                i++;
            }
            cout << "\nВыпал (x" << coefficient() << ")  You lose " << bet_price << " $ " << endl;
            check_balance();
        }

    }
    //int check_event() {
    //    try
    //    {
    //        if () {

    //        }
    //    }
    //    catch (const exception&)
    //    {

    //    }
    //    return 1;
    //}


    ~Money()
    {
        cout << " Вызов диструктора Money\n";
    }


};

int main()
{
    setlocale(LC_ALL, "rus");
    unsigned int start_balance = 1000;

    Money new_session;
    new_session.current_balance = start_balance;

    while ( true ) {

        cout << "Привет друг! Играем? yes, no" << endl;
        string start;
        cin >> start;
        if (start == "yes") {
            cout << "Ну ок)" << endl;;
        }
        else {
            return 0;
        }
        new_session.bet_event();



    }


    return 0;

}