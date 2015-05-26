#include "skill.h"

Skill::Skill(const QString& name,
             bool isTrained):
    name(name),
    isTrained(isTrained) {
}



const QString& Skill::getName() const {
    return name;
}



bool Skill::getTrained() const {
    return isTrained;
}



void Skill::setName(const QString& name) {
    this->name = name;
}



void Skill::setTrained(bool isTrained) {
    this->isTrained = isTrained;
}
