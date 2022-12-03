/********************************************************************************
** Form generated from reading UI file 'layer.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYER_H
#define UI_LAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Layer
{
public:

    void setupUi(QWidget *Layer)
    {
        if (Layer->objectName().isEmpty())
            Layer->setObjectName("Layer");
        Layer->resize(400, 300);

        retranslateUi(Layer);

        QMetaObject::connectSlotsByName(Layer);
    } // setupUi

    void retranslateUi(QWidget *Layer)
    {
        Layer->setWindowTitle(QCoreApplication::translate("Layer", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Layer: public Ui_Layer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYER_H
