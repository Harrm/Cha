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



const Character::Name& Character::getName() const {
    return name;
}



Character::Level Character::getLevel() const {
    return level;
}
