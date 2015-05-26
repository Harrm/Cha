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



void Character::setSkillTrained(Name skill_name, bool is_trained) {
    if(auto iterator = skills.find(skill_name) != skills.end()) {
        iterator = is_trained;
    }
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



bool Character::isSkillTrained(Name skill_name) const {
    return skills.find(skill_name).value();
}



const QMap<Character::Name, bool>&
    Character::getSkills() const {

    return skills;
}



const Character::Name& Character::getName() const {
    return name;
}



Character::Level Character::getLevel() const {
    return level;
}
