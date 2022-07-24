#include <QtTest>
#include <TestCanvas.h>


int main(int argc, char** argv)
{
   QGuiApplication theTestApp(argc, argv);
   auto status {0};

   {
      TestCanvas tc;    // Test class for Canvas
      status |= QTest::qExec(&tc, argc, argv);
   }
   return status;
}
