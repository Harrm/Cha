#pragma once
#ifndef CHARACTER_READER_H
#define CHARACTER_READER_H

#include <QXmlStreamReader>
class Character;



class CharacterReader: public QXmlStreamReader {
    enum Result {Error = 0, Ok = 1};
    using Path = const QString&;

public:
    CharacterReader();
    virtual ~CharacterReader();
    
    Character* readCharacter(Path path);
    
private:
    Result setFile(Path path);

    Result readElement();
    void readCharacterTag();
    Result readNameTag();
    Result readAbilityTag();

    void deleteCharacter();

    Character* character;
    
};

#endif // CHARACTER_READER_H
