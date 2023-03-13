TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += "../L_Variable/include"

INCLUDEPATH += "../L_Utility/include"
INCLUDEPATH += "../L_Utility/include/Data_Structures"
INCLUDEPATH += "../L_Utility/include/Debug"

win32 {
    LIBS += "../../L_Variable/Build/debug/libMDL_Parser.a"
    LIBS += "../../L_Utility/Build/debug/libL_Utility.a"
}

unix {
    LIBS += "../../L_Variable/Build/libL_Variable.a"
    LIBS += "../../L_Utility/Build/libL_Utility.a"
}
