/********************************************************************************
** Form generated from reading UI file 'rentdossierpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENTDOSSIERPANEL_H
#define UI_RENTDOSSIERPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RentDossierPanel
{
public:
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
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lHouseK;
    QLineEdit *lID;
    QLineEdit *lCommission;
    QLineEdit *lMortgage;
    QLineEdit *lRent;
    QLineEdit *lRentTime;
    QLineEdit *lFPrice;
    QHBoxLayout *horizontalLayout;
    QPushButton *pRequest;
    QPushButton *pHouse;
    QPushButton *pSave;

    void setupUi(QDialog *RentDossierPanel)
    {
        if (RentDossierPanel->objectName().isEmpty())
            RentDossierPanel->setObjectName(QString::fromUtf8("RentDossierPanel"));
        RentDossierPanel->resize(294, 285);
        widget = new QWidget(RentDossierPanel);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 256, 243));
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

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lHouseK = new QLineEdit(widget);
        lHouseK->setObjectName(QString::fromUtf8("lHouseK"));

        verticalLayout_2->addWidget(lHouseK);

        lID = new QLineEdit(widget);
        lID->setObjectName(QString::fromUtf8("lID"));

        verticalLayout_2->addWidget(lID);

        lCommission = new QLineEdit(widget);
        lCommission->setObjectName(QString::fromUtf8("lCommission"));

        verticalLayout_2->addWidget(lCommission);

        lMortgage = new QLineEdit(widget);
        lMortgage->setObjectName(QString::fromUtf8("lMortgage"));

        verticalLayout_2->addWidget(lMortgage);

        lRent = new QLineEdit(widget);
        lRent->setObjectName(QString::fromUtf8("lRent"));

        verticalLayout_2->addWidget(lRent);

        lRentTime = new QLineEdit(widget);
        lRentTime->setObjectName(QString::fromUtf8("lRentTime"));

        verticalLayout_2->addWidget(lRentTime);

        lFPrice = new QLineEdit(widget);
        lFPrice->setObjectName(QString::fromUtf8("lFPrice"));
        lFPrice->setReadOnly(true);

        verticalLayout_2->addWidget(lFPrice);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pRequest = new QPushButton(widget);
        pRequest->setObjectName(QString::fromUtf8("pRequest"));

        horizontalLayout->addWidget(pRequest);

        pHouse = new QPushButton(widget);
        pHouse->setObjectName(QString::fromUtf8("pHouse"));

        horizontalLayout->addWidget(pHouse);

        pSave = new QPushButton(widget);
        pSave->setObjectName(QString::fromUtf8("pSave"));

        horizontalLayout->addWidget(pSave);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(RentDossierPanel);

        QMetaObject::connectSlotsByName(RentDossierPanel);
    } // setupUi

    void retranslateUi(QDialog *RentDossierPanel)
    {
        RentDossierPanel->setWindowTitle(QCoreApplication::translate("RentDossierPanel", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RentDossierPanel", "House Kind:", nullptr));
        label_2->setText(QCoreApplication::translate("RentDossierPanel", "ID [Apartments] :", nullptr));
        label_3->setText(QCoreApplication::translate("RentDossierPanel", "Commission: ", nullptr));
        label_4->setText(QCoreApplication::translate("RentDossierPanel", "Mortgage: ", nullptr));
        label_5->setText(QCoreApplication::translate("RentDossierPanel", "Rent: ", nullptr));
        label_6->setText(QCoreApplication::translate("RentDossierPanel", "Rent Time: ", nullptr));
        label_7->setText(QCoreApplication::translate("RentDossierPanel", "Final Price: ", nullptr));
        pRequest->setText(QCoreApplication::translate("RentDossierPanel", "Request", nullptr));
        pHouse->setText(QCoreApplication::translate("RentDossierPanel", "House", nullptr));
        pSave->setText(QCoreApplication::translate("RentDossierPanel", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RentDossierPanel: public Ui_RentDossierPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENTDOSSIERPANEL_H
