#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{
    _name = "";
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _pride_points = 0;
    _age = 1;
}

Player::Player(string name, int age, int strength, int stamina, int wisdom)
{
    _name = name;
    _age = age;
    _pride_points = 20000;

    if(strength > 1000 || strength < 100)
    {
        _strength = 100;
    }else{
        _strength = strength;
    }

    if(stamina > 1000 || stamina < 100)
    {
        _stamina = 100;
    }else{
        _stamina = stamina;
    }

    if(wisdom > 1000 || wisdom < 100)
    {
        _wisdom = 100;
    }else{
        _wisdom = wisdom;
    }
}



string Player::getName()
{
    cout << "Name: " << _name << endl;
    return _name;
}

int Player::getStrength()
{
    return _strength;
}

int Player::getStamina()
{
    return _stamina;
}

int Player::getWisdom()
{
    return _wisdom;
}

int Player::getPridePoints()
{
    return _pride_points;
}

int Player::getAge()
{
    return _age;
}

void Player::setName(string name)
{
    _name = name;
}

void Player::setStrength(int strength)
{
    _strength = strength;
}

void Player::setStamina(int stamina)
{
    _stamina = stamina;
}

void Player::setWisdom(int wisdom)
{
    _wisdom = wisdom;
}

void Player::setPridePoints(int pridePoints)
{
    _pride_points = pridePoints;
}

void Player::setAge(int age)
{
    _age = age;
}

void Player::trainCub(int strength, int stamina, int wisdom)
{
    _strength += strength;
    _stamina += stamina;
    _wisdom += wisdom;
    _pride_points -= 5000;
}

void Player::toPrideLands()
{
    _pride_points += 5000;
    _strength -= 2000;
    _wisdom -= 2000;
    _stamina -= 1000;
}

void Player::printStats()
{
    cout << "Strength: " << _strength << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Wisdom: " << _wisdom << endl;
    cout << "Pride Points: " << _pride_points << endl;
}
