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
