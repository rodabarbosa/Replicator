#include "enemy.h"
#include "game.h"

extern Game * game; // call global variable
                    // it cant be inserted in the header file

Enemy::Enemy(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent) {
    // set position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // draw enemy
    //setRect(0, 0, 100, 100);
    setPixmap(QPixmap(":/img/enemy.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move() {
    // move enemy
    setPos(x(), y()+10);

    // if collides destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i) {
        if(typeid(*(colliding_items[i])) == typeid(Ship)) {
            // remove enemy
            scene()->removeItem(this);

            // clear memory
            delete this;

            // decrease the score
            game->live->decrease();

            if(game->live->getLive() < 1) {
                game->player->gameOver();
            }

            return;
        }
    }

    if(pos().y()+100 >= scene()->height()+150) {
        scene()->removeItem(this);
        delete this;
    }
}
