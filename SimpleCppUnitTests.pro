QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    tests/unittests/SimpleCppUnitTestsMain.cpp \
    tests/unittests/TestCanvas.cpp \
    src/Canvas.cpp

HEADERS += \
    tests/unittests/TestCanvas.h \
    src/Canvas.h

INCLUDEPATH += \
    src \
    tests/unittests
