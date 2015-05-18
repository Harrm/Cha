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



void Character::setAbilityValue(Name ability_name, Value value) {
    if(abilities.contains(ability_name)) {
        *(abilities.find(ability_name)) = value;
    }
}



void Character::upLevel() {
    level++;
}



const QMap<Character::Name, Character::Value>&
    Character::getAbilities() const {

    return abilities;
}



Character::Value Character::getAbilityValue(Name ability_name) const {
    return abilities.find(ability_name).value();
}



Character::Value Character::getAbilityModifier(Name ability_name) const {
    auto value = abilities.find(ability_name).value();
    auto modifier = (value - 10) % 2;
    return modifier;
}



const Character::Name& Character::getName() const {
    return name;
}



Character::Level Character::getLevel() const {
    return level;
}
