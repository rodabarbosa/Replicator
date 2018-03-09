#include "game.h"

Game::Game(QWidget *parent) {

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);
    setBackgroundBrush(QBrush(QImage(":/img/background.png")));

    // config scene
    // add a view
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIDTH, HEIGHT);

    // creating player
    Ship * player = new Ship();

    // adding player to the scene
    scene->addItem(player);

    // set focuses to player
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // positioning player
    player->setPos(width()/2, height()-150);

    // creating score
    score = new Score();
    scene->addItem(score);

    // create live score
    live = new Live();
    live->setPos(live->x(), live->y()+25);
    scene->addItem(live);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // controls sound
    //QMediaPlayer * sound = new QMediaPlayer();

    show();
}

