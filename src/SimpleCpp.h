namespace simplecpp {
    class Sprite;
    class Turtle;

    void initCanvas(const unsigned width, const unsigned height);
    void closeCanvas();
    Turtle& theSystemTurtle();
    int canvas_width();
    int canvas_height();
    void addSprite(Sprite *t);
    void repaint();
    void removeSprite(Sprite *t);
    void c_imprint(Sprite* s);
    void beginFrame();
    void endFrame();
    void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill=true, unsigned int line_width=2, int line_style=1, int cap_style=1, int join_style=1, int fill_rule=1, int function=1);
    void drawLine(XPoint start, XPoint end, Color line_color, unsigned int line_width);
}
