#pragma once
#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include <QWidget>
#include "character/character_reader.h"
class Character;
class QGridLayout;
class NameScreen;
class AbilityScreen;



class CharacterBuilder: public QWidget {

    Q_OBJECT

public:
    CharacterBuilder(QWidget* parent = nullptr);
    virtual ~CharacterBuilder() = default;

private:
    Character* character;
    CharacterReader reader;
    QGridLayout* layout;

    NameScreen* nameScreen;
    AbilityScreen* abilityScreen;
};

#endif // CHARACTER_BUILDER_H

