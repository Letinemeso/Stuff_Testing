TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += "../Utility/include"

win32 {
    LIBS += "../../Utility/Build/debug/libUtility.a"
}

unix {
    LIBS += "../../Utility/Build/libUtility.a"
}
