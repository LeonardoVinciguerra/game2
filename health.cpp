#include "health.h"
#include <QFont>
extern bool finish;
Health::Health(QGraphicsItem*parent):QGraphicsTextItem(parent)
{
    health = 5;
    // put on the screen
    setPlainText("Health:"+ QString::number(health)); // Health: 5
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    if (health > 0)
        setPlainText("Health:"+ QString::number(--health));
    else
       finish = 1;
        
    


}

int Health::getHealth()
{
    return health;
}
