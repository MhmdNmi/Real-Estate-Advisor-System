/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lUsername;
    QLineEdit *lPassword;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rManager;
    QRadioButton *rNUser;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pLogin;
    QPushButton *pSignup;
    QPushButton *pClose;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(295, 160);
        layoutWidget = new QWidget(login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 256, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lUsername = new QLineEdit(layoutWidget);
        lUsername->setObjectName(QString::fromUtf8("lUsername"));

        gridLayout->addWidget(lUsername, 0, 1, 1, 1);

        lPassword = new QLineEdit(layoutWidget);
        lPassword->setObjectName(QString::fromUtf8("lPassword"));

        gridLayout->addWidget(lPassword, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rManager = new QRadioButton(layoutWidget);
        rManager->setObjectName(QString::fromUtf8("rManager"));

        horizontalLayout->addWidget(rManager);

        rNUser = new QRadioButton(layoutWidget);
        rNUser->setObjectName(QString::fromUtf8("rNUser"));

        horizontalLayout->addWidget(rNUser);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pLogin = new QPushButton(layoutWidget);
        pLogin->setObjectName(QString::fromUtf8("pLogin"));

        horizontalLayout_2->addWidget(pLogin);

        pSignup = new QPushButton(layoutWidget);
        pSignup->setObjectName(QString::fromUtf8("pSignup"));

        horizontalLayout_2->addWidget(pSignup);

        pClose = new QPushButton(layoutWidget);
        pClose->setObjectName(QString::fromUtf8("pClose"));

        horizontalLayout_2->addWidget(pClose);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("login", "Username: ", nullptr));
        label_2->setText(QCoreApplication::translate("login", "Password: ", nullptr));
        rManager->setText(QCoreApplication::translate("login", "Manager", nullptr));
        rNUser->setText(QCoreApplication::translate("login", "Normal User", nullptr));
        pLogin->setText(QCoreApplication::translate("login", "Log In", nullptr));
        pSignup->setText(QCoreApplication::translate("login", "Sign Up", nullptr));
        pClose->setText(QCoreApplication::translate("login", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
