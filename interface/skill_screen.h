#pragma once
#ifndef SKILLSCREEN_H
#define SKILLSCREEN_H

#include <QWidget>
#include <QVector>
class QLabel;
class QCheckBox;
class QButtonGroup;
class QVBoxLayout;



class SkillScreen: public QWidget {

    Q_OBJECT

public:
    SkillScreen(QWidget* parent = nullptr);
    virtual ~SkillScreen() = default;

    void setSkillsList(const QMap<QString, bool> skills_list);
    void setChecked(const QString& skill_name, bool checked);
    bool isChecked(const QString& skill_name);

signals:
    void skillChecked(const QString& name, bool is_check);

private:
    void createHeader();

    QButtonGroup* checkBoxesGroup;
    QVector<QCheckBox*> checkBoxes;
    QVBoxLayout* layout;
};

#endif // SKILLSCREEN_H
