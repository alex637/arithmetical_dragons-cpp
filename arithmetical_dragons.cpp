#include <iostream>
#include <sstream>
#include <cstdlib>
#include <list>

#include "unit.h"
#include "hero.h"
#include "dragon.h"
#include "troll.hpp"

using namespace std;


void showHealth(const Hero &hero, const Dragon &dragon)
{
    cout << "Hero health: " << hero.getHealth()
        << ", Dragon health: " << dragon.getHealth() << endl;
}

list<Dragon*> generateDragonList()
{
    list<Dragon*> competitors;
    competitors.push_back(new GreenDragon());
    competitors.push_back(new RedDragon());
    competitors.push_back(new BlackDragon());
	
    return competitors;
}


bool playGame(Hero &hero, list<Dragon*> &dragons)
{
    bool gameOver = false;

    for (list<Dragon*>::iterator dragon = dragons.begin();
            dragon != dragons.end(); dragon++)
    {
        cout << "You have met a new " << (*dragon)->color() << " dragon. Fight!" << endl;

        while ((*dragon)->isAlive() && hero.isAlive())
        {
            hero.attack(**dragon);
        }
        if (!hero.isAlive())
        {
            gameOver = true;
            break;
        }
        else // dragon was killed!
        {
            hero.addScores(Dragon::c_killScores);
            cout << "Ough! You have killed a dragon!" << endl;
        }
    }
    return gameOver;
}


list<Troll*> generateTrollList()
{
    list<Troll*> competitors;
    competitors.push_back(new DecToHexTroll());
    	
    return competitors;
}

bool playGame(Hero &hero, list<Troll*>& trolls)
{
    bool gameOver = false;

    for (auto troll : trolls) //pointer!
    {
        cout << "You have met a new " << troll->color() << " troll. Fight!" << endl;

        while (troll->isAlive() && hero.isAlive())
        {
            hero.attack(*troll);
        }
        if (!hero.isAlive())
        {
            gameOver = true;
            break;
        }
        else // a troll was killed!
        {
            hero.addScores(Troll::c_killScores);
            cout << "Ough! You have killed a troll!" << endl;
        }
    }
    return gameOver;
}


int main()
{
    Hero hero;
    //list<Dragon*> dragons = generateDragonList();
    list<Troll*> trolls = generateTrollList();
    bool gameResult = playGame(hero, trolls);

    if (gameResult)
    {
        cout << "Game over! Your score is: " << hero.getScores() << endl;
    }
    else
    {
        cout << "You win! Your score is: " << hero.getScores() << endl;
    }
    /*
    for (list<Dragon*>::iterator dragon = dragons.begin();
            dragon != dragons.end(); dragon++)
        delete *dragon;
    */
    for (auto troll_ptr : trolls)
    {
    	delete troll_ptr;
    }
    
    return 0;
}
