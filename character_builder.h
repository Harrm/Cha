#pragma once
#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include <QWidget>
#include "character/character_reader.h"
class Character;
class QGridLayout;
class NameScreen;
class AbilityScreen;
class SkillScreen;



class CharacterBuilder: public QWidget {

    Q_OBJECT

public:
    CharacterBuilder(QWidget* parent = nullptr);
    virtual ~CharacterBuilder() = default;

private:
    void createScreens();
        void createNameScreen();
        void createAbilityScreen();
        void createSkillScreen();

    Character* character;
    CharacterReader reader;
    QGridLayout* layout;

    NameScreen* nameScreen;
    AbilityScreen* abilityScreen;
    SkillScreen* skillScreen;
};

#endif // CHARACTER_BUILDER_H
