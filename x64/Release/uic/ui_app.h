/********************************************************************************
** Form generated from reading UI file 'app.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_appClass
{
public:
    QWidget *centralWidget;
    QLabel *title_market;
    QListWidget *listWidget;
    QGroupBox *grp_iteminfo;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *iteminfo_price;
    QLabel *iteminfo_uid;
    QLabel *iteminfo_bsgid;
    QLabel *img_selecteditem;
    QLineEdit *lineEdit;

    void setupUi(QMainWindow *appClass)
    {
        if (appClass->objectName().isEmpty())
            appClass->setObjectName(QString::fromUtf8("appClass"));
        appClass->resize(600, 400);
        centralWidget = new QWidget(appClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        title_market = new QLabel(centralWidget);
        title_market->setObjectName(QString::fromUtf8("title_market"));
        title_market->setGeometry(QRect(10, 10, 200, 50));
        title_market->setAutoFillBackground(true);
        title_market->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 101, 261, 161));
        grp_iteminfo = new QGroupBox(centralWidget);
        grp_iteminfo->setObjectName(QString::fromUtf8("grp_iteminfo"));
        grp_iteminfo->setGeometry(QRect(10, 270, 261, 121));
        verticalLayoutWidget = new QWidget(grp_iteminfo);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 241, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        iteminfo_price = new QLabel(verticalLayoutWidget);
        iteminfo_price->setObjectName(QString::fromUtf8("iteminfo_price"));

        verticalLayout->addWidget(iteminfo_price);

        iteminfo_uid = new QLabel(verticalLayoutWidget);
        iteminfo_uid->setObjectName(QString::fromUtf8("iteminfo_uid"));

        verticalLayout->addWidget(iteminfo_uid);

        iteminfo_bsgid = new QLabel(verticalLayoutWidget);
        iteminfo_bsgid->setObjectName(QString::fromUtf8("iteminfo_bsgid"));

        verticalLayout->addWidget(iteminfo_bsgid);

        img_selecteditem = new QLabel(centralWidget);
        img_selecteditem->setObjectName(QString::fromUtf8("img_selecteditem"));
        img_selecteditem->setGeometry(QRect(280, 70, 75, 75));
        img_selecteditem->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 70, 261, 22));
        appClass->setCentralWidget(centralWidget);

        retranslateUi(appClass);

        QMetaObject::connectSlotsByName(appClass);
    } // setupUi

    void retranslateUi(QMainWindow *appClass)
    {
        appClass->setWindowTitle(QCoreApplication::translate("appClass", "app", nullptr));
        title_market->setText(QCoreApplication::translate("appClass", "title_market", nullptr));
        grp_iteminfo->setTitle(QCoreApplication::translate("appClass", "Item Information", nullptr));
        iteminfo_price->setText(QCoreApplication::translate("appClass", "Price:", nullptr));
        iteminfo_uid->setText(QCoreApplication::translate("appClass", "uid: ", nullptr));
        iteminfo_bsgid->setText(QCoreApplication::translate("appClass", "bsgid: ", nullptr));
        img_selecteditem->setText(QCoreApplication::translate("appClass", "img_selecteditem", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("appClass", "search items..", nullptr));
    } // retranslateUi

};

namespace Ui {
    class appClass: public Ui_appClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
