#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullett.h"
#include "enemy.h"
#include <string.h>
extern char im[40];
Player::Player()
{
    setPixmap(QPixmap(":/images/cat.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() < 700)
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+40,y());
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_U){
        // create a bullet
        strcpy(im,":/images/Nik_3.png");
    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
