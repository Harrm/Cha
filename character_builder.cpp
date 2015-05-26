#include "character_builder.h"
#include <QLabel>
#include <QGridLayout>
#include "character/character_reader.h"
#include "character/character.h"
#include "interface/name_screen.h"
#include "interface/ability_screen.h"
#include "interface/skill_screen.h"



CharacterBuilder::CharacterBuilder(QWidget* parent):
    QWidget(parent) {

    layout = new QGridLayout(this);
    character = reader.readCharacter("data/default_character.xml");

    createScreens();

    setLayout(layout);
    resize(300, 300);
}



void CharacterBuilder::createScreens() {
    createNameScreen();
    createAbilityScreen();
    createSkillScreen();
}



void CharacterBuilder::createNameScreen() {
    nameScreen = new NameScreen(this);
    layout->addWidget(nameScreen, 0, 0, Qt::AlignLeft);
    connect(nameScreen, &NameScreen::nameChanged,
            this,        [this](const Character::Name& name) {character->setName(name);});

}



void CharacterBuilder::createAbilityScreen() {
    abilityScreen = new AbilityScreen(this);

    QMap<Ability::Name, Ability::Value> abilities;
    for(auto& ability : character->getAbilities()) {
        abilities.insert(ability.getName(), ability.getValue());
    }
    abilityScreen->setAbilitiesList(abilities);

    connect(abilityScreen, &AbilityScreen::abilityChanged,
            [this](const QString& ability_name, u_int16_t value) {
                character->getAbility(ability_name).setValue(value);
            });
    layout->addWidget(abilityScreen, 1, 0, Qt::AlignLeft);
}



void CharacterBuilder::createSkillScreen() {
    skillScreen = new SkillScreen(this);
    QMap<Character::Name, bool> skills;
    for(auto& skill : character->getSkills()) {
        skills.insert(skill.getName(), skill.getTrained());
    }
    skillScreen->setSkillsList(skills);

    connect(skillScreen, &SkillScreen::skillChecked,
            [this](const QString& skill_name, bool is_trained) {
                character->getSkill(skill_name).setTrained(is_trained);
            });
    layout->addWidget(skillScreen, 1, 1, 2, 1);
}
