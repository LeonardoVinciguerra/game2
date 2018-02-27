#include <QApplication>

#include "game.h"

Game * game;
bool finish = 0;
char im[40]=":/images/emiligame.png";

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    game = new Game;
    return a.exec();
}
