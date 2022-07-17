#include <sprite.h>
#include <turtle.h>

namespace simplecpp{

static QRect calculateCanvasSize() {
    auto rect = theApp.primaryScreen()->availableGeometry();
    auto topLeft = rect.topLeft();
    auto sz = rect.size() * (2.0 / 3.0);
    return QRect(topLeft, sz);
}

// C++ standard guarantess the order of initialization of static variables in the same file.
// They are initialized in the order they are declared.
// Refer to "Ordered Dynamic Initialization" in https://en.cppreference.com/w/cpp/language/initialization
// Following order is signicant as Qt application must be created before initializing any GUI classes
static int argc = 1;
static char *appName = "Simplecpp";
static QGuiApplication theApp(argc, &appName);
static Canvas theCanvas(simplecpp::calculateCanvasSize());
static Turtle theSystemTurtleObj;

    void initCanvas(const unsigned width, const unsigned height) {
    }

    void closeCanvas() {
    }

    Turtle& theSystemTurtle() {
        return theSystemTurtleObj;
    }

    int canvas_width() {
        return theCanvas.width();
    }

    int canvas_height() {
        return theCanvas.height();
    }

    void addSprite(Sprite *){
        // if(t){
        //     spriteSet.insert(t);
        // }
    }

    void repaint() {}
    void removeSprite(Sprite *) {}
    void c_imprint(Sprite* s) {s->paint(nullptr);}
    void beginFrame() {}
    void endFrame() {}
    void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int fill_rule, int function){}
    void drawLine(XPoint start, XPoint end, Color line_color, unsigned int line_width){
        theCanvas.drawLine(start, end, line_color, line_width);
    }
}   // End of simplecpp namespace
