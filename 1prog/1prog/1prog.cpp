// программа рулетка


#include <fstream>
#include <iostream>
#include <time.h>       /* time */
#include <string>
#include "windows.h"


using namespace std;



class Wheel {
    
public:
    Wheel() {
        srand(time(NULL));
        cout << " Добро пожаловать в рулеточку)" << endl;
    }
    enum Colors {
        BLACK = 1,
        RED = 2,
        BLUE = 3,
        GOLD = 4,
    };



    int winner;

    // Вычисления выигрышного числа
    int randomizer(){
       
        winner = 1+rand() % 4;
        return winner;
    }


    // Соотношение цвета и кооф на умножение ставки
    int coefficient() {
        int coefficient = 0;
        switch (winner)
        {
        case BLACK:
            coefficient = 2;
            break;
        case RED:
            coefficient = 3;
            break;
        case BLUE:
            coefficient = 5;
            break;
        case GOLD:
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
        cout << " Wheeеееееl\n";
        Sleep(1000);
    }

};



class Money : public Wheel {
     //Constructor
public:
    long current_balance = 1000;
    Money() {
        cout << " У тебя на балансе: " << current_balance <<  "$ " << endl;
    }
    long bet_price;
    int enter_money() {
    tryAgain_money:
    cout << " Введите сколько поставить: \n";
    cin >> bet_price;
        if (bet_price > current_balance) {
            cout << " У вас недостаточно денег! \n";
            goto tryAgain_money;
        }
        else if (bet_price == 0) {
            cout << " Не возможно поставить число 0! \n";
            goto tryAgain_money;
        }
        else if (bet_price <= 0) {
            cout << " Нельзя ставить отрицательные числа! \n";
            goto tryAgain_money;
        }
        else {  
            return bet_price;
        }



      
    }

    // Уменчить баланс
    int minus() {
        return current_balance = current_balance - bet_price;
    }
    // Увеличить баланс
    int plus() {
        return current_balance += bet_price * coefficient(); 
         
    }

    int betted_color() {
        string color_str;
        int betted_color;
        tryAgain_color:
            cout << " На который цвет поставить? black/red/blue/gold \n";
            cin >> color_str;
            if (color_str == "black" || color_str == "1") {
                betted_color = BLACK;
            }
            else if (color_str == "red" || color_str == "2")
            {
                betted_color = RED;
            }
            else if (color_str == "blue" || color_str == "3")
            {
                betted_color = BLUE;
            }
            else if (color_str == "gold" || color_str == "4")
            {
                betted_color = GOLD;
            }
            else {
                cout << " Не правильно выбран цвет, нужно вписать black или red или blue или gold\n";
                goto tryAgain_color;
                
            }
            return betted_color;
            

    }


    int check_balance() {
        cout << " Баланс: " << current_balance << endl;
        return current_balance;
    }


    void bet_event() {
        enter_money();
        int pre_balance = current_balance;
        if (betted_color() == randomizer()) {
            minus();
            plus();
            cout << " -" << bet_price << " $ ";
            cout << " Рулетка крутится ! \n";
            int i = 0;
            while (i != 10) {
                Sleep(100);
                cout << " . ";
                i++;
            }
            cout << "\n Выпал (x" << coefficient() << ") : +" << current_balance - pre_balance << " $ ";
            check_balance();
        }
        else {
            minus();
            cout << " -" << bet_price << " $ ";
            cout << " Рулетка крутится ! \n";
            int i = 0;
            while (i != 10) {
                Sleep(100);
                cout << " . ";
                i++;
            }
            cout << "\n Выпал (x" << coefficient() << ")  You lose " << bet_price << " $ " << endl;
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
        cout << " Спасибо что просрали деньги у нас)\n";
    }


};

int main()
{
    setlocale(LC_ALL, "rus");
    int start_balance = 1000;

    Money new_session;
    new_session.current_balance = start_balance;

    while ( true ) {

        string start;
    again:
        cout << " Играем? yes, no" << endl;
        cin >> start;
        if (start == "yes" || start == "y" || start == "да") {
            cout << " Ну ок)" << endl;;
        }
        else if (start == "no") {
            return 0;
        }
        else {
            goto again;
        }
        new_session.bet_event();



    }


    return 0;

}