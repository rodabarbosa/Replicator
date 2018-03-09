#include "bullet.h"
#include "game.h"

extern Game * game; // call global variable
                    // it cant be inserted in the header file

Bullet::Bullet(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent) {
    // draw graphic
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/img/bullet.png"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(move()));

    timer->start(50);
}

void Bullet::move() {

    // if collides destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i) {
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // inscrease the score
            if(game->live->getLive() > 0) {
                game->score->increase();
            }

            // remove them
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // clear memory
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    // move the bullet up
    setPos(x(), y()-45);

    if(pos().y() + 50 < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
