#pragma once
#ifndef ABILITY_H
#define ABILITY_H



#include <QString>



class Ability {
public:
    using Name = QString;
    using Value = u_int16_t;

    Ability(Name name = "No name", Value value = 10);

    void setName(const Name& name);
    void setValue(Value value);

    const Name& getName() const;
    Value getValue() const;
    Value getModifier() const;

private:
    Name name;
    Value value;
};

#endif // ABILITY_H
