#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>



class Character{
    using Level = u_int8_t;
    using Name = QString;

public:
    Character();
    Character(const Name& name, Level level = 1);
    Character(Level level);
    Character(const Character& character);
    Character(const Character* character);

    ~Character() = default;

    void setName(const Name& name);
    void upLevel();

    Name getName();
    Level getLevel();

private:
    Name name;
    Level level;
};

#endif // CHARACTER_H
