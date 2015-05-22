#pragma once
#ifndef ABILITYSCREEN_H
#define ABILITYSCREEN_H

#include <QWidget>
class QLabel;
class QSpinBox;
class QGridLayout;
class QGridLayout;



class AbilityScreen: public QWidget {

    Q_OBJECT

public:
    AbilityScreen(QWidget* parent = nullptr);
    virtual ~AbilityScreen() = default;

    void setAbilitiesList(const QMap<QString, u_int16_t>& abilities_list);
    void setAbilityValue(const QString& ability_name, u_int16_t value);

signals:
    void abilityChanged(const QString& name, u_int16_t value);

private:
    class Line;

    void createHeader();
    QGridLayout* layout;
    QVector<Line*> abilities;

};

#endif // ABILITYSCREEN_H
