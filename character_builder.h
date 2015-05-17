#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include <QWidget>
#include "character/character_reader.h"
class Character;
class QGridLayout;



class CharacterBuilder: public QWidget {

    Q_OBJECT

public:
    CharacterBuilder(QWidget* parent = nullptr);
    virtual ~CharacterBuilder() = default;


private:
    Character* character;
    CharacterReader reader;
    QGridLayout* layout;
};

#endif // CHARACTER_BUILDER_H

