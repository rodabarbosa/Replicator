#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QBrush>
#include <QImage>
#include "ship.h"
#include "score.h"
#include "live.h"

class Game: public QGraphicsView {
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Ship * player;
    Score * score;
    Live * live;


private:
    const int HEIGHT = 600;
    const int WIDTH  = 800;

    const int PLAYER_HEIGHT = 100;
    const int PLAYER_WIDTH  = 100;
    const int MARGIN = 10;

};

#endif // GAME_H
