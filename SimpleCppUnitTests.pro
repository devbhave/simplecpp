QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

# Code coverage is enabled in debug mode
QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage  # Compile with code coverage enabled
QMAKE_LFLAGS_DEBUG += -lgcov --coverage                 # Link coverage profiler libraries

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
