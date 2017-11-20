#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include <string>
#include <iostream>

#include "dragon.h"
#include "troll.hpp"

class Hero: public Unit
{
    int scores;
public:
    static const int default_health = 100;
    static const int default_attackForce = 20;

    Hero(int health = default_health, int aForce = default_attackForce)
        :Unit(health, aForce), scores(0)
    {}
    void attack (Dragon &drago)
    {
        std::string q = drago.generateQuestion();
        std::cout << "question: " << q;
        //int answer;
        //std::cin >> answer;
        if (drago.checkAnswer())
        {
            drago.getDamage(attackForce);
            std::cout << "Hit you, dragon!" << std::endl;
        }
        else
        {
            getDamage(drago.attackForce);
            std::cout << "Hero suffers..." << std::endl;
        }
    }
    
    void attack (Troll &troll)
    {
        std::string q = troll.generateQuestion();
        std::cout << "question: " << q;
        //std::string answer;
        //std::cin >> answer;
        if (troll.checkAnswer())
        {
            troll.getDamage(attackForce);
            std::cout << "Hit you, troll!" << std::endl;
        }
        else
        {
            getDamage(troll.attackForce);
            std::cout << "Hero suffers..." << std::endl;
        }
    }
    
    int getScores() { return scores; }
    
    void addScores(int value)
    {
    	scores += value;
    }
};

#endif // HERO_H_INCLUDED
