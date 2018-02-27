#include "bullett.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"
extern Game * game; //external global object

Bullet::Bullet(QGraphicsItem*parent):QObject(),QGraphicsPixmapItem(parent){
    // drew the rect
    setPixmap(QPixmap(":/images/ciambella1.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(5);
}

void Bullet::move(){
    QList<QGraphicsItem * > colliding_items = collidingItems();
    for ( int i = 0, n = colliding_items.size(); i < n; i++ ){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;

            return;
        }
    }
    // move bullet up
    setPos(x(),y()-2);
    if (pos().y() < -50 ){
            scene()->removeItem(this);
            delete this;}
}
