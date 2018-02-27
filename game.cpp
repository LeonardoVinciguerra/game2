#include "game.h"
#include <QFont>
#include "player.h"
#include <QGraphicsTextItem>
#include <QTimer>
#include "enemy.h"
#include <QMediaPlayer>
Game::Game(QWidget * parent)
{
    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    Player * player = new Player();
    // add the item to the scene
    scene->addItem(player);

    // make rect focusable for Qkey events
      player->setFlag(QGraphicsItem::ItemIsFocusable);
      player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    player->setPos(340,480);
    view->setBackgroundBrush(QBrush(Qt::blue,Qt::SolidPattern));

    // create the score
    score = new Score();
    scene->addItem(score);

    //create health
    health = new Health();
    health->setPos(0,25);
    scene->addItem(health);


    // spawn
    QTimer* timer = new QTimer();
    timer->start(2000);
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/723.mp3"));
    music->play();

}
