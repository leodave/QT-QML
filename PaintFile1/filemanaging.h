#ifndef FILEMANAGING_H
#define FILEMANAGING_H

#include <QObject>

class FileManaging : public QObject
{
    Q_OBJECT
public:
    explicit FileManaging(QObject *parent = nullptr);

signals:

};

#endif // FILEMANAGING_H
