//Madeline Boss
//COP 3330
//Programming Assignment 5
//header file
#include <iostream>
using namespace std;

class Car
{
protected:
    int speed;
    int topSpeed;
    int current;

public:
    Car();
    virtual ~Car();
    virtual int getSpeed() = 0;
    virtual int getCurrent() = 0;
    virtual void setCurrent(int current) = 0;

    virtual int SpeedUp() = 0;
};

class Sedan: public Car
{
    public:
        int SpeedUp();
        Sedan(int speed);
        int getSpeed();
        int getCurrent();
        void setCurrent(int current);
};

class HatchBack : public Car
{
    public:
        int SpeedUp();
        HatchBack(int speed);
        int getSpeed();
        int getCurrent();
        void setCurrent(int current);
};

class RaceCar : public Car
{
    public:
        int SpeedUp();
        RaceCar(int speed);
        int getSpeed();
        int getCurrent();
        void setCurrent(int current);

};