#include "character.h"

Character::Character():
    name("Anonymous"),
    level(1){
}



Character::Character(const Name& name, Level level):
    name(name),
    level(level) {
}



Character::Character(Level level):
    Character(){
    this->level = level;
}



Character::Character(const Character& character):
    name(character.name),
    level(character.level){
}



Character::Character(const Character* character):
    name(character->name),
    level(character->level){
}



void Character::setName(const Name& name) {
    this->name = name;
}




void Character::upLevel() {
    level++;
}



Character::Value Character::getProfiency() const {
    return level/5 + 2;
}



const QList<Ability>& Character::getAbilities() const {
    return abilities;
}



const Ability& Character::getAbility(const QString& name) const {
    for(auto& ability : abilities) {
        if(ability.getName() == name) {
            return ability;
        }
    }
}



Ability& Character::getAbility(const QString& name) {
    for(auto& ability : abilities) {
        if(ability.getName() == name) {
            return ability;
        }
    }
}



Skill& Character::getSkill(Name skill_name) {
    for(auto& skill : skills) {
        if(skill.getName() == name) {
            return skill;
        }
    }
}



const Skill& Character::getSkill(Name skill_name) const {
    for(auto& skill : skills) {
        if(skill.getName() == name) {
            return skill;
        }
    }
}



const QList<Skill>& Character::getSkills() const {
    return skills;
}



const Character::Name& Character::getName() const {
    return name;
}



Character::Level Character::getLevel() const {
    return level;
}
