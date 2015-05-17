#pragma once
#ifndef NAME_SCREEN_H
#define NAME_SCREEN_H

#include <QWidget>
#include "character/character.h"
class QLineEdit;
class QHBoxLayout;
class QSpinBox;



class NameScreen: public QWidget {

    Q_OBJECT

public:
    NameScreen(QWidget* parent = nullptr);
    virtual ~NameScreen() = default;

    void setName(Character::Name name);
    void setLevel(Character::Level level);

signals:
    void nameChanged(Character::Name name);
    void levelChanged(Character::Level level);

private:
    QHBoxLayout* layout;
    QLineEdit* nameEdit;
    QSpinBox* levelEdit;

};

#endif // NAME_SCREEN_H
