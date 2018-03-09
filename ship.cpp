#include "ship.h"

Ship::Ship(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent) {
    // draw graphic
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/img/player.png"));

}

void Ship::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left) {

        if(pos().x() > 0) {
            setPos(x()-10,y());
        }

    }
    else if(event->key() == Qt::Key_Right) {

        if(pos().x()+100 < scene()->width()) {
            setPos(x()+10,y());
        }

    } else if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Space) {

        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

    }
}

void Ship::gameOver()
{
    //this->hide();

    return;
}

void Ship::spawn() {
    // create a enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}


