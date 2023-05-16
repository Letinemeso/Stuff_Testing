TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += "../L_Utility/include"
INCLUDEPATH += "../L_Gamedev_Lib/include"

win32 {
    LIBS += "../../L_Utility/Build/debug/libL_Utility.a"
    LIBS += "../../L_Gamedev_Lib/Build/debug/libL_Gamedev_Lib.a"
}

unix {
    LIBS += "../../L_Utility/Build/libL_Utility.a"
    LIBS += "../../L_Gamedev_Lib/Build/libL_Gamedev_Lib.a"
}
