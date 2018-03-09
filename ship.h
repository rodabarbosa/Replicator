#ifndef MYRECT
#define MYRECT

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"

#include <QDebug>

class Ship: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Ship(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void gameOver();

public slots:
    void spawn();
};

#endif // MYRECT

