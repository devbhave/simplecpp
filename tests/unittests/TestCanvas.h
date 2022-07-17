#include <QObject>

class TestCanvas : public QObject
{
   Q_OBJECT

private Q_SLOTS:
   void verifyCanvasConstruction();
};
