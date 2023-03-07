#ifndef OPENGLGRAPGICS_H
#define OPENGLGRAPGICS_H

#include <QOpenGLFunctions_1_1>
#include <QObject>

class OpenGlGrapgics : public QOpenGLFunctions_1_1
{
    Q_OBJECT
public:
    OpenGlGrapgics();
};

#endif // OPENGLGRAPGICS_H
