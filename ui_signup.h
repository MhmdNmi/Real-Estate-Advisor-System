/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lName;
    QLineEdit *lUsername;
    QLineEdit *lPassword;
    QLineEdit *lRPassword;
    QLineEdit *lFCredit;
    QHBoxLayout *horizontalLayout;
    QSpinBox *sbYear;
    QSpinBox *sbMonth;
    QSpinBox *sbDay;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rManager;
    QRadioButton *rNUser;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pRegister;
    QPushButton *pCancel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QString::fromUtf8("signup"));
        signup->resize(311, 316);
        signup->setSizeIncrement(QSize(500, 500));
        centralwidget = new QWidget(signup);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 273, 246));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lName = new QLineEdit(widget);
        lName->setObjectName(QString::fromUtf8("lName"));

        verticalLayout_2->addWidget(lName);

        lUsername = new QLineEdit(widget);
        lUsername->setObjectName(QString::fromUtf8("lUsername"));

        verticalLayout_2->addWidget(lUsername);

        lPassword = new QLineEdit(widget);
        lPassword->setObjectName(QString::fromUtf8("lPassword"));

        verticalLayout_2->addWidget(lPassword);

        lRPassword = new QLineEdit(widget);
        lRPassword->setObjectName(QString::fromUtf8("lRPassword"));

        verticalLayout_2->addWidget(lRPassword);

        lFCredit = new QLineEdit(widget);
        lFCredit->setObjectName(QString::fromUtf8("lFCredit"));

        verticalLayout_2->addWidget(lFCredit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sbYear = new QSpinBox(widget);
        sbYear->setObjectName(QString::fromUtf8("sbYear"));

        horizontalLayout->addWidget(sbYear);

        sbMonth = new QSpinBox(widget);
        sbMonth->setObjectName(QString::fromUtf8("sbMonth"));

        horizontalLayout->addWidget(sbMonth);

        sbDay = new QSpinBox(widget);
        sbDay->setObjectName(QString::fromUtf8("sbDay"));

        horizontalLayout->addWidget(sbDay);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rManager = new QRadioButton(widget);
        rManager->setObjectName(QString::fromUtf8("rManager"));

        horizontalLayout_3->addWidget(rManager);

        rNUser = new QRadioButton(widget);
        rNUser->setObjectName(QString::fromUtf8("rNUser"));

        horizontalLayout_3->addWidget(rNUser);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pRegister = new QPushButton(widget);
        pRegister->setObjectName(QString::fromUtf8("pRegister"));

        horizontalLayout_4->addWidget(pRegister);

        pCancel = new QPushButton(widget);
        pCancel->setObjectName(QString::fromUtf8("pCancel"));

        horizontalLayout_4->addWidget(pCancel);


        verticalLayout_3->addLayout(horizontalLayout_4);

        signup->setCentralWidget(centralwidget);
        menubar = new QMenuBar(signup);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 311, 25));
        signup->setMenuBar(menubar);
        statusbar = new QStatusBar(signup);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        signup->setStatusBar(statusbar);

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QMainWindow *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("signup", "Name: ", nullptr));
        label_2->setText(QCoreApplication::translate("signup", "Username: ", nullptr));
        label_3->setText(QCoreApplication::translate("signup", "Password: ", nullptr));
        label_4->setText(QCoreApplication::translate("signup", "ReWrite Password: ", nullptr));
        label_5->setText(QCoreApplication::translate("signup", "First Credit: ", nullptr));
        label_6->setText(QCoreApplication::translate("signup", "BirthDay: ", nullptr));
        rManager->setText(QCoreApplication::translate("signup", "Manager", nullptr));
        rNUser->setText(QCoreApplication::translate("signup", "Normal User", nullptr));
        pRegister->setText(QCoreApplication::translate("signup", "Register", nullptr));
        pCancel->setText(QCoreApplication::translate("signup", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
