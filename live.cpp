#include "live.h"

Live::Live(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // live start at 3
    live = 3;

    // draw the text
    setPlainText(QString("Live: ") + QString::number(live));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}

void Live::increase() {
    live++;
    setPlainText(QString("Live: ") + QString::number(live));
}

void Live::decrease() {
    live--;
    setPlainText(QString("Live: ") + QString::number(live));

    if(live <= 0) {
        // game over
        // draw the text
        setPlainText(QString("GAME OVER"));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times", 32));
        setPos(250, 250);


    }
}

int Live::getLive() {
    return live;
}
