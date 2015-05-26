#include "ability_screen_line.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>



AbilityScreen::Line::Line(const QString& ability_name, QWidget* parent):
    QWidget(parent) {

    name = new QLabel(ability_name, this);
    valueSpin = new QSpinBox(this);
    valueSpin->setMaximumWidth(70);
    modifier = new QLabel(this);

    void (QSpinBox::*f)(int) = &QSpinBox::valueChanged;
    connect(valueSpin, f, this, &Line::setValue);
}



QLabel* AbilityScreen::Line::getNameLabel() {
    return name;
}



QSpinBox* AbilityScreen::Line::getValueButton() {
    return valueSpin;
}



QLabel* AbilityScreen::Line::getModifierLabel() {
    return modifier;
}



void AbilityScreen::Line::setValue(u_int16_t value) {
    this->valueSpin->setValue(value);
    modifier->setText(QString::number(((value / 2) - 5)));
    emit valueChanged(value);
}



u_int16_t AbilityScreen::Line::getValue() const {
    return valueSpin->value();
}



const QString& AbilityScreen::Line::getName() const {
    return name->text();
}
