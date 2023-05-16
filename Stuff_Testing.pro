TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += "../L_Utility/include"

win32 {
    LIBS += "../../L_Utility/Build/debug/libL_Utility.a"
}

unix {
    LIBS += "../../L_Utility/Build/libL_Utility.a"
}
