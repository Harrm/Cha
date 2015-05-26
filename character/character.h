#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include <QMap>
#include <character/ability.h>



class Character {
    friend class CharacterReader;

public:
    using Level = u_int8_t;
    using Name = QString;
    using Value = u_int16_t;

    Character();
    Character(const Name& name, Level level = 1);
    Character(Level level);
    Character(const Character& character);
    Character(const Character* character);

    ~Character() = default;

    void setName(const Name& name);
    void upLevel();
    void setAbilityValue(Name ability_name, Value value);
    void setSkillTrained(Name skill_name, bool is_trained);

    const Name& getName() const;
    Level getLevel() const;
    Value getProfiency() const;
    const Ability& getAbility(const QString& name) const;
    Ability& getAbility(const QString& name);
    const QList<Ability>& getAbilities() const;
    bool isSkillTrained(Name skill_name) const;
    const QMap<Name, bool>& getSkills() const;

private:
    Name name;
    Level level;
    QList<Ability> abilities;
    QMap<Name, bool> skills;
};

#endif // CHARACTER_H
