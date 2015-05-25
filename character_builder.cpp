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

    nameScreen = new NameScreen(this);
    layout->addWidget(nameScreen, 0, 0);
    connect(nameScreen, &NameScreen::nameChanged,
            this,        [this](const Character::Name& name) {character->setName(name);});

    abilityScreen = new AbilityScreen(this);
    abilityScreen->setAbilitiesList(character->getAbilities());
    connect(abilityScreen, &AbilityScreen::abilityChanged,
            [this](const QString& ability_name, u_int16_t value) {
                character->setAbilityValue(ability_name, value);
            });
    layout->addWidget(abilityScreen, 1, 0);

    skillScreen = new SkillScreen(this);
    skillScreen->setSkillsList(character->getSkills());
    connect(skillScreen, &SkillScreen::skillChecked,
            [this](const QString& skill_name, bool is_trained) {
                character->setSkillTrained(skill_name, is_trained);
            });
    layout->addWidget(skillScreen, 1, 1, 2, 1);

    setLayout(layout);
    resize(300, 300);
}
