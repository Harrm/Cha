#include "character_reader.h"
#include <QFile>
#include <QMessageBox>
#include "character.h"



CharacterReader::CharacterReader() {
    character = nullptr;
}



CharacterReader::~CharacterReader() {
    if (character != nullptr) {
        delete character;
    }
}



Character* CharacterReader::readCharacter(const QString& path) {
    if(character != nullptr) {
        delete character;
    }

    QFile file(path);
    
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error when read character", "File not found:"+path);
        return nullptr;
    }
    
    setDevice(&file);

    while(not atEnd()) {
        switch(readNext()) {
        case StartElement:
            if (name() == "character") {
                (attributes().hasAttribute("level")) ?
                            character = new Character(attributes().value("level").toUShort())
                :           character = new Character;
            } else if (name() == "name") {
                if (readNext() == Characters) {
                    character->setName(text().toString());
                }
            }
            break;
        case EndDocument:
            return character;

        default:
            break;
        }
    }
    
    if(hasError()) {
        QMessageBox::critical(nullptr, "Error when read character", errorString());
    }

    return nullptr;
}
