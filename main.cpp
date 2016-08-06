#include <QGuiApplication>
#include <QOpenGLContext>
#include <QOffscreenSurface>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QDebug>


int main(int argn, char** argv) {
    QGuiApplication app(argn, argv);

    QSurfaceFormat format;
    format.setMajorVersion(3);
    format.setMinorVersion(3);

    QOpenGLContext context;
    context.setFormat(format);
    context.create();
    if (!context.isValid()) return 1;
    qDebug() << QString::fromLatin1("Context created.");

    QOffscreenSurface surface;
    surface.setFormat(format);
    surface.create();
    if(!surface.isValid()) return 2;
    qDebug() << QString::fromLatin1("Surface created.");

    context.makeCurrent(&surface);

    QOpenGLFunctions f;
    f.initializeOpenGLFunctions();
    qDebug() << QString::fromLatin1("OpenGLFunctions initialized.");
    qDebug() << QString::fromLatin1((const char*)f.glGetString(GL_VERSION));

    return 0;
}
