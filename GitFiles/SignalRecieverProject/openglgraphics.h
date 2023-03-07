#ifndef OPENGLGRAPHICS_H
#define OPENGLGRAPHICS_H

#include <QOpenGLFunctions_1_1>
#include <QObject>

class OpenGLGraphics : public QOpenGLFunctions_1_1
{
    Q_OBJECT
public:
    OpenGLGraphics();
};

#endif // OPENGLGRAPHICS_H
