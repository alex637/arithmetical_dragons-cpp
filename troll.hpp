#ifndef TROLL_HEADER_INCLUDED
#define TROLL_HEADER_INCLUDED

#include <string>
#include <sstream>

class Troll: public Unit
{
protected:
    int my_answer;
    std::string my_type;
public:
    static const int c_killScores = 200;

    Troll(std::string type, int start_health, int _attackForce)
        :Unit(start_health, _attackForce), my_type(type)
    {}

    virtual std::string generateQuestion() = 0;

    virtual bool checkAnswer() const = 0;
    
    std::string color() const
    {
        return my_type;
    }
};

class DecToHexTroll: public Troll
{
    static const int c_DecToHexTrollHealth = 50;
    static const int c_DecToHexTrollAttackForce = 5;
public:

    DecToHexTroll()
        :Troll("DecToHex", c_DecToHexTrollHealth,
                 c_DecToHexTrollAttackForce)
    {}
    
	virtual std::string generateQuestion()
    {
        int value = 1 + rand()%100;

        std::stringstream question;
        question << "Transform to hex: " << value << " is ";
        my_answer = value;
        return question.str();
    }
    
    virtual bool checkAnswer() const
    {
    	int answer;
    	std::cin >> std::hex >> answer;
    	return answer == my_answer;
    }
};




#endif // TROLL_HEADER_INCLUDED
