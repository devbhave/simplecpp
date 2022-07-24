#include <Canvas.h>
#include <TestCanvas.h>
#include <QTest>

void TestCanvas::verifyCanvasConstruction(){
    auto left {100}, top  {50};
    auto width {800}, height {600};

    Canvas c(QRect(left, top, width, height));

    QVERIFY2(c.visibility() == QWindow::Windowed, "Canvas window should have been visible");

    QVERIFY2(c.x() == left, "Canvas window: Incorrect left corner position");
    QVERIFY2(c.y() == top,  "Canvas window: Incorrect top corner position");

    QVERIFY2(c.width() == width,    "Canvas window: Incorrect width");
    QVERIFY2(c.height() == height,  "Canvas window: Incorrect height");

    QVERIFY2(c.title() == "SimpleCpp",  "Canvas window: Incorrect window title");

    // REQ: System background colour should be canvas background colour
    auto screenPixels = c.screen()->grabWindow().toImage();
    auto actualBackgroundColour = screenPixels.pixelColor(400, 300);
    auto expectedBackgroundColour = QGuiApplication::palette().brush(QPalette::Window).color();
    QVERIFY2(actualBackgroundColour == expectedBackgroundColour, "Canvas window: Incorrect canvas background colour");
}
