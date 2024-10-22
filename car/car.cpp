//Madeline Boss
//COP 3330
//Programming Assignment 5
//Definition file

#include "car.h"

//======== Car ========//
Car::Car()
{
    speed = 0;
    topSpeed = 0;
    current = 0;
}

Car::~Car()
{

}

//======== Sedan =========//
Sedan::Sedan(int speed)
{
    this -> speed = speed;
    topSpeed = 2;
    current = 0;
}

int Sedan::SpeedUp()
{
    if(speed < topSpeed)
    {
        speed++;
    }

    else
        speed = speed;

    return speed;
}

int Sedan::getSpeed()
{
    return speed;
}

int Sedan::getCurrent()
{
    return current;
}

void Sedan::setCurrent(int current)
{
    this -> current = current;
}

//======== HatchBack ========//
HatchBack::HatchBack(int speed)
{
    this -> speed = speed;
    topSpeed = 3;
    current = 0;
}

int HatchBack::SpeedUp()
{
    if(speed < topSpeed)
    {
        speed++;
    }

    else
    {
        speed = speed;
    }

    return speed;
}

int HatchBack::getSpeed()
{
    return speed;
}

int HatchBack::getCurrent()
{
    return current;
}

void HatchBack::setCurrent(int current)
{
    this -> current = current;
}

//======== RaceCar ========//
RaceCar::RaceCar(int speed)
{
    this -> speed = speed;
    topSpeed = 5;
    current = 0;
}

int RaceCar::SpeedUp()
{
    if(speed < topSpeed)
    {
        speed++;
    }

    else
    {
        speed = speed;
    }

    return speed;
}

int RaceCar::getSpeed()
{
    return speed;
}

int RaceCar::getCurrent()
{
    return current;
}

void RaceCar::setCurrent(int current)
{
    this -> current = current;
}
