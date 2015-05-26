#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include <QMap>
#include <character/ability.h>
#include <character/skill.h>



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
    Ability& getAbility(const QString& name);
    Skill& getSkill(Name skill_name);

    const Name& getName() const;
    Level getLevel() const;
    Value getProfiency() const;
    const Ability& getAbility(const QString& name) const;
    const QList<Ability>& getAbilities() const;
    const Skill& getSkill(Name skill_name) const;
    const QList<Skill>& getSkills() const;

private:
    Name name;
    Level level;
    QList<Ability> abilities;
    QList<Skill> skills;
};

#endif // CHARACTER_H
