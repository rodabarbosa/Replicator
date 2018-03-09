#ifndef LIVE_H
#define LIVE_H

#include <QGraphicsTextItem>
#include <QFont>

class Live: public QGraphicsTextItem {
public:
    Live(QGraphicsItem * parent = 0);
    void increase();
    void decrease();
    int getLive();

private:
    int live;
};

#endif // LIVE_H
