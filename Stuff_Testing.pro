TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += "../MDL_Parser/include"

INCLUDEPATH += "../Utility/include"
INCLUDEPATH += "../Utility/include/Data_Structures"
INCLUDEPATH += "../Utility/include/Debug"

win32 {
    LIBS += "../../MDL_Parser/Build/debug/libMDL_Parser.a"
    LIBS += "../../Utility/Build/debug/libUtility.a"
}

unix {
    LIBS += "../../MDL_Parser/Build/libMDL_Parser.a"
    LIBS += "../../Utility/Build/libUtility.a"
}
