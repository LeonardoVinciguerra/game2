#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem*parent):QGraphicsTextItem(parent)
{
    score = 0;
    // put on the screen
    setPlainText("Score:"+ QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Score::increase()
{
    setPlainText("Score:"+ QString::number(++score));
}

int Score::getScore()
{
    return score;
}
