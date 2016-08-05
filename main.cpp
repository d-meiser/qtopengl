#include <QGuiApplication>
#include <QOpenGLContext>
#include <QOffscreenSurface>
#include <QSurfaceFormat>
#include <QOpenGLFunctions_3_3_Core>
#include <QDebug>


int main(int argn, char** argv) {
    QGuiApplication app(argn, argv);

    QSurfaceFormat format;
    format.setMajorVersion(3);
    format.setMinorVersion(3);

    QOpenGLContext context;
    context.setFormat(format);
    context.create();
    if (!context.isValid()) return -1;

    QOffscreenSurface surface;
    surface.setFormat(format);
    surface.create();
    if(!surface.isValid()) return -2;

    context.makeCurrent(&surface);

    QOpenGLFunctions_3_3_Core f;
    if(!f.initializeOpenGLFunctions()) return -3;

    qDebug() << QString::fromLatin1((const char*)f.glGetString(GL_VERSION));

    return 0;
}
