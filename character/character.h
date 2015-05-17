#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>



class Character {
public:
    using Level = u_int8_t;
    using Name = QString;

    Character();
    Character(const Name& name, Level level = 1);
    Character(Level level);
    Character(const Character& character);
    Character(const Character* character);

    ~Character() = default;

    void setName(const Name& name);
    void upLevel();

    const Name& getName() const;
    Level getLevel() const;

private:
    Name name;
    Level level;
};

#endif // CHARACTER_H
