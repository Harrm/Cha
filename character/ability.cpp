#include "ability.h"

Ability::Ability(Name name, Value value):
    name(name),
    value(value) {


}



void Ability::setName(const Name& name) {
    this->name = name;
}



void Ability::setValue(Value value) {
    this->value = value;
}



const Ability::Name& Ability::getName() const {
    return name;
}



Ability::Value Ability::getValue() const {
    return value;
}



Ability::Value Ability::getModifier() const {
    return (value - 10) % 2;
}
