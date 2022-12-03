/********************************************************************************
** Form generated from reading UI file 'dialogagregarevento.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAGREGAREVENTO_H
#define UI_DIALOGAGREGAREVENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogAgregarEvento
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *DialogAgregarEvento)
    {
        if (DialogAgregarEvento->objectName().isEmpty())
            DialogAgregarEvento->setObjectName("DialogAgregarEvento");
        DialogAgregarEvento->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogAgregarEvento);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogAgregarEvento);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 341, 16));
        lineEdit = new QLineEdit(DialogAgregarEvento);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 70, 331, 22));

        retranslateUi(DialogAgregarEvento);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogAgregarEvento, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogAgregarEvento, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogAgregarEvento);
    } // setupUi

    void retranslateUi(QDialog *DialogAgregarEvento)
    {
        DialogAgregarEvento->setWindowTitle(QCoreApplication::translate("DialogAgregarEvento", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogAgregarEvento", "evento nuevo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAgregarEvento: public Ui_DialogAgregarEvento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAGREGAREVENTO_H
