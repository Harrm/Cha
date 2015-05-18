#include "character_reader.h"
#include <QFile>
#include <QMessageBox>
#include "character.h"



CharacterReader::CharacterReader() {
    character = nullptr;
}



CharacterReader::~CharacterReader() {
    deleteCharacter();
}



Character* CharacterReader::readCharacter(Path path) {
    deleteCharacter();

    QFile file(path);

    if(not file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error when read character", "File not found:"+path);
        return nullptr;
    }
    setDevice(&file);

    while(not atEnd()) {
        switch(readNext()) {
        case StartElement:
            if(readElement() == Error) {
                deleteCharacter();
                return nullptr;
            }
            break;

        case EndElement:
            if (name() == "character") {
                return character;
            }

        default:
            ;
        }
    }
    
    if(hasError()) {
        QMessageBox::critical(nullptr, path+": error when read character", errorString());
    }

    return nullptr;
}



CharacterReader::Result CharacterReader::setFile(Path path) {
    QFile file(path);

    if(not file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error when read character", "File not found:"+path);
        return Error;
    }

    setDevice(&file);
    return Ok;
}



CharacterReader::Result CharacterReader::readElement() {
    if (name() == "character") {
        readCharacterTag();

    } else if (name() == "name") {
        if (readNameTag() == Error) {
            QMessageBox::critical(nullptr, "Error when read character", "Invalid character name");
            return Error;
        }
    } else if (name() == "ability") {
        if (readAbilityTag() == Error) {
            QMessageBox::critical(nullptr, "Error when read character", "Invalid ability");
            return Error;
        }
    }
    return Ok;
}



void CharacterReader::readCharacterTag() {
    if (attributes().hasAttribute("level")) {
        character = new Character(attributes().value("level").toUShort());

    } else {
        character = new Character;
    }
}



CharacterReader::Result CharacterReader::readNameTag() {
    if (readNext() == Characters) {
        character->setName(text().toString());
        return Ok;

    } else {
        return Error;
    }
}



CharacterReader::Result CharacterReader::readAbilityTag() {
    Character::Name ability_name = "Undefined";
    Character::Value ability_value = 10;

    if (attributes().hasAttribute("name") and attributes().hasAttribute("value")) {
        ability_name = attributes().value("name").toString();
        ability_value = attributes().value("value").toShort();

        character->abilities.insert(ability_name, ability_value);

    } else {
        return Error;
    }

    return Ok;
}



void CharacterReader::deleteCharacter() {
    if(character != nullptr) {
        delete character;
        character = nullptr;
    }
}
