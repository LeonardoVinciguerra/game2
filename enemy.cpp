#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"

extern Game * game;
extern char im[40];
Enemy::Enemy(){
    int random = rand() % 700;
    // drew the rect
    setPixmap(QPixmap(im));
    setPos(random,0);
    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){

    setPos(x(),y()+5);
    if (pos().y() > 600 ){
            game->health->decrease();
            scene()->removeItem(this);
            delete this;}
}
