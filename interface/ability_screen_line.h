#pragma once
#ifndef LINE_H
#define LINE_H

#include "ability_screen.h"

class QLabel;
class QSpinBox;



class AbilityScreen::Line: public QWidget {

    Q_OBJECT

public:
    Line(const QString& ability_name, QWidget* parent = nullptr);
    virtual ~Line() = default;

    QLabel* getNameLabel();
    QSpinBox* getValueButton();
    QLabel* getModifierLabel();

    void setValue(u_int16_t valueSpin);
    u_int16_t getValue() const;

    const QString& getName() const;

signals:
    void valueChanged(u_int8_t valueSpin);

private:
    QLabel* name;
    QSpinBox* valueSpin;
    QLabel* modifier;
};


#endif // LINE_H
