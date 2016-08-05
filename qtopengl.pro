QT += quick
TEMPLATE = app
TARGET = qtopengl

linux-g++ {
    QMAKE_CXXFLAGS += "-Wall -Wextra -Werror"
}

SOURCES = \
    main.cpp
