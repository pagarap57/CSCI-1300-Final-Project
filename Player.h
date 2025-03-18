#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
    public:
        Player();
        Player(string name, int age, int strength, int stamina, int wisdom);
        string getName();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        int getAge();
        void setName(string name);
        void setStrength(int strength);
        void setStamina(int stamina);
        void setWisdom(int wisdom);
        void setPridePoints(int pridePoints);
        void setAge(int age);
        void trainCub(int strength, int stamina, int wisdom);
        void toPrideLands();
        void printStats();

    private: 
        string _name;
        int _strength;
        int _stamina;
        int _wisdom;
        int _pride_points;
        int _age;
};

#endif
