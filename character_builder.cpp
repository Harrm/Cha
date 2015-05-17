#include "character_builder.h"
#include <QLabel>
#include <QGridLayout>
#include "character/character_reader.h"
#include "character/character.h"
#include "interface/name_screen.h"



CharacterBuilder::CharacterBuilder(QWidget* parent):
    QWidget(parent) {

    layout = new QGridLayout(this);
    character = reader.readCharacter("data/default_character.xml");

    nameScreen = new NameScreen(this);

    layout->addWidget(nameScreen, 0, 0);

    connect(nameScreen, &NameScreen::nameChanged,
            this,        [this](const Character::Name& name) {character->setName(name);});

    setLayout(layout);
    resize(300, 300);
}
