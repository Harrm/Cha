#include "skill_screen.h"
#include <QVector>
#include <QLabel>
#include <QCheckBox>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QMap>



SkillScreen::SkillScreen(QWidget* parent):
    QWidget(parent) {

    layout = new QVBoxLayout(this);
    checkBoxesGroup = new QButtonGroup(this);
    checkBoxesGroup->setExclusive(false);

    createHeader();

    setLayout(layout);
}



void SkillScreen::createHeader() {
    layout->addWidget(new QLabel("Skill:", this));
}



void SkillScreen::setSkillsList(const QMap<QString, bool> skills_list) {
    checkBoxes.clear();

    for(short c = 0; c < skills_list.size(); c++) {
        auto skill_name = skills_list.keys().at(c);
        auto is_trained = skills_list.value(skill_name);

        checkBoxes.push_back(new QCheckBox(skill_name, this));
        checkBoxes.back()->setCheckState((is_trained)? Qt::Checked : Qt::Unchecked);
        checkBoxesGroup->addButton(checkBoxes.back(), c);
        layout->addWidget(checkBoxes.back());
    }

    void (QButtonGroup::*buttonChecked)(QAbstractButton* button, bool is_check) = &QButtonGroup::buttonToggled;
    connect(checkBoxesGroup, buttonChecked,
            [this](QAbstractButton* button, bool is_check) {
                emit skillChecked(button->text(), is_check);
            });
    setLayout(layout);
}



void SkillScreen::setChecked(const QString& skill_name, bool checked) {
    for(auto* checkBox : checkBoxes) {
        if(checkBox->text() == skill_name) {
            checkBox->setChecked(checked);
        }
    }
}



bool SkillScreen::isChecked(const QString& skill_name) {
    for(auto* checkBox: checkBoxes) {
        if(checkBox->text() == skill_name) {
            return checkBox->checkState();
        }
    }
    return false;
}
