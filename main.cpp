#include <QOpenGLContext>
#include <QOffscreenSurface>
#include <QOpenGLFunctions>


struct MyRenderer : protected QOpenGLFunctions {
    void initGL() {
        initializeOpenGLFunctions();
    }
};


int main(int argn, char** argv) {
    Q_UNUSED(argn);
    Q_UNUSED(argv);

    QOpenGLContext context;
    context.create();
    QOffscreenSurface surface;
    surface.create();
    context.makeCurrent(&surface);

    return 0;
}
