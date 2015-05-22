#include "ability_screen.h"
#include <QLabel>
#include <QSpinBox>
#include <QButtonGroup>
#include <QBoxLayout>
#include "ability_screen_line.h"



AbilityScreen::AbilityScreen(QWidget* parent):
    QWidget(parent) {

    layout = new QGridLayout(this);
    createHeader();
    setLayout(layout);
}



void AbilityScreen::createHeader() {
    layout->addWidget(new QLabel("Name:", this), 0, 0);
    layout->addWidget(new QLabel("Value:", this), 0, 1);
    layout->addWidget(new QLabel("Modifier:", this), 0, 2);
}



void AbilityScreen::setAbilityValue(const QString& ability_name, u_int16_t value) {
    for (auto* ability : abilities) {
        if(ability->getName() == ability_name) {
            ability->setValue(value);
        }

    }
}



void AbilityScreen::setAbilitiesList(const QMap<QString, u_int16_t>& abilities_list) {
    abilities.clear();

    for(short c = 0; c < abilities_list.size(); c++) {
        auto ability_name = abilities_list.keys().at(c);
        auto ability_value = abilities_list.value(ability_name);

        abilities.push_back(new Line(ability_name, this));
        abilities.back()->setValue(ability_value);

        layout->addWidget(abilities.back()->getNameLabel(), c+1, 0);
        layout->addWidget(abilities.back()->getValueButton(), c+1, 1);
        layout->addWidget(abilities.back()->getModifierLabel(), c+1, 2);
    }
    setLayout(layout);
}
