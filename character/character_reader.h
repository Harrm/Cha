#pragma once
#ifndef CHARACTER_READER_H
#define CHARACTER_READER_H

#include <QXmlStreamReader>
class Character;



class CharacterReader: public QXmlStreamReader {
public:
    CharacterReader();
    virtual ~CharacterReader();
    
    Character* readCharacter(const QString& path);
    
    
private:
    Character* character;
    
};

#endif // CHARACTER_READER_H
