#include "character_builder.h"
#include <QLabel>
#include <QGridLayout>
#include "character/character_reader.h"
#include "character/character.h"



CharacterBuilder::CharacterBuilder(QWidget* parent):
    QWidget(parent) {

    layout = new QGridLayout(this);
    character = reader.readCharacter("data/default_character.xml");

    layout->addWidget(new QLabel(character->getName(), this), 0, 0);

    setLayout(layout);
    resize(300, 300);
}
