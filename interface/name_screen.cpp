#include "name_screen.h"
#include <QLineEdit>
#include <QSpinBox>
#include <QHBoxLayout>



NameScreen::NameScreen(QWidget* parent):
    QWidget(parent) {

    layout = new QHBoxLayout(this);

    nameEdit = new QLineEdit(this);
    levelEdit = new QSpinBox(this);
    levelEdit->setRange(1, 20);

    connect(nameEdit, &QLineEdit::textEdited,
            this,      &NameScreen::nameChanged);

    void (QSpinBox::*valueChange)(int) = &QSpinBox::valueChanged;
    connect(levelEdit, valueChange,
            this,       &NameScreen::levelChanged);

    layout->addWidget(nameEdit);
    layout->addWidget(levelEdit);
    setLayout(layout);
}



void NameScreen::setName(Character::Name name) {
    nameEdit->setText(name);
}



void NameScreen::setLevel(Character::Level level) {
    levelEdit->setValue(level);
}
