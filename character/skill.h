#pragma once
#ifndef SKILL_H
#define SKILL_H

#include <QString>



class Skill {
public:
    Skill(const QString& name = "No name",
          bool isTrained = false);

    const QString& getName() const;
    bool getTrained() const;

    void setName(const QString& name);
    void setTrained(bool isTrained);

private:
    QString name;
    bool isTrained;

};

#endif // SKILL_H
