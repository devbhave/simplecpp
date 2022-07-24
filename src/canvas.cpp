#include <Canvas.h>


Canvas::Canvas(QRect canvasPosition):offScreenBuffer(this) {
    // Set window size including top left corner position, height, and width
    setGeometry(canvasPosition);
    setTitle("SimpleCpp");

    // Set screen buffer size to window's size    
    auto screenSize = QSize(width(), height());
    offScreenBuffer.resize(screenSize);

    // Fill the screen buffer with a background colour
    auto brush = QGuiApplication::palette().brush(QPalette::Window);
    auto fillRegion = QRegion(0, 0, screenSize.width(), screenSize.height());

    offScreenBuffer.beginPaint(fillRegion);
    QPaintDevice *device = offScreenBuffer.paintDevice();
    Q_ASSERT(device != nullptr);
    QPainter painter(device);
    painter.fillRect(fillRegion.boundingRect(), brush);
    painter.end();
    offScreenBuffer.endPaint();

    // Show the window
    show();

    // Wait till window is exposed
    while(!isExposed()) {
        QGuiApplication::processEvents();
        QThread::msleep(100);
    }
}

void Canvas::exposeEvent(QExposeEvent *e)
{
    if (isExposed())
        render(e->region());
}

void Canvas::render(const QRegion &dirtyRegion) {
    if (!isExposed())
        return;

    // Flush screen buffer to window to update dirty region
    offScreenBuffer.flush(dirtyRegion.boundingRect());
}


void Canvas::drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth) {
    auto fillRegion = QRegion(0, 0, width(), height());

    // Get resources
    QPen pen(lineColor);
    pen.setWidth(lineWidth);

    offScreenBuffer.beginPaint(fillRegion);
    QPaintDevice *device = offScreenBuffer.paintDevice();
    Q_ASSERT(device != nullptr);
    QPainter painter(device);

    // Do the drawing
    painter.setPen(pen);
    painter.drawLine(start, end);

    painter.end();
    offScreenBuffer.endPaint();

    // Update the window
    offScreenBuffer.flush(fillRegion.boundingRect());

    QGuiApplication::processEvents();
}
