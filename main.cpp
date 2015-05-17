#include <QApplication>
#include "character_builder.h"



int main(int argc, char** argv){
    QApplication app(argc, argv);
    CharacterBuilder cb;
    cb.show();

    return app.exec();
}
