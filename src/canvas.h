#ifndef _CANVAS_INCLUDED
#define _CANVAS_INCLUDED

#include <memory>
#include <algorithm>

#include <QtGui>
#include <QDebug>

typedef QPoint XPoint ;
typedef QColor Color;


class Canvas : public QWindow{
    Q_OBJECT
    QBackingStore offScreenBuffer;

protected:
    virtual void exposeEvent(QExposeEvent *event) override;

public:    
    Canvas(QRect canvasPosition);
    ~Canvas() = default;
    void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);

public slots:
    virtual void render(const QRegion &dirtyRegion);
};


#endif
