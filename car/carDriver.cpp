//Madeline Boss
//COP 3330
//Programming Assignment 5
//Driver file

#include "car.h"

int main()
{
    int size = 0;
    int capacity = 4;
    int count = 0;
    Car* cars[capacity];
    char choice = 'o';
    int finish = 25;



    cout << "Welcome to the Race Simulator!" << endl;

    while(count < capacity)
    {
        cout << "Please select a car to race!" << endl;
        cout << "(S)edan" << endl;
        cout << "(H)atchBack" << endl;
        cout << "(R)aceCar" << endl;
        cout << "Selected car: ";
        cin >> choice;

        switch(choice)
        {
            case 'S':
            case 's':
            {
                cars[size++] = new Sedan(0);
                break;
            }

            case 'H':
            case 'h':
            {
                cars[size++] = new HatchBack(0);
                break;
            }

            case 'R':
            case 'r':
            {
                cars[size++] = new RaceCar(0);
                break;
            }


        }

        count++;
    }

    bool final = false;
    int i = 0;
    int winner = 0;
    while(final == false)
    {
        for ( i  = 0; i < size; i++)
        {
            cars[i] -> SpeedUp();
            cars[i] -> setCurrent((cars[i] -> getCurrent()) + (cars[i] -> getSpeed()));

            if(cars[i] -> getCurrent() >= finish)
            {
                final = true;
                winner = i + 1;
            }

        }
    }

    cout << "The winner is car " << winner << "!" << endl;

    for(int i = 0; i < capacity; i++)
    {
        delete cars[i];
    }

    return 0;

}
