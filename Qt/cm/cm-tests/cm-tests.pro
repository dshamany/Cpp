include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

QT += testlib
QT -= gui
TARGET = client-tests

CONFIG += qt console warn_on depend_includepath testcase c++14
CONFIG -= app_bundle

INCLUDEPATH += source

TEMPLATE = app

SOURCES +=  \
    source/models/client-tests.cpp

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui
