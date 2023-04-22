/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *selectCategoryDropDown;
    QComboBox *sortByDropDown;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchButton;
    QTableView *foodTable;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(635, 546);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        selectCategoryDropDown = new QComboBox(centralwidget);
        selectCategoryDropDown->setObjectName("selectCategoryDropDown");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectCategoryDropDown->sizePolicy().hasHeightForWidth());
        selectCategoryDropDown->setSizePolicy(sizePolicy1);
        selectCategoryDropDown->setCursor(QCursor(Qt::PointingHandCursor));
        selectCategoryDropDown->setEditable(true);
        selectCategoryDropDown->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_3->addWidget(selectCategoryDropDown);

        sortByDropDown = new QComboBox(centralwidget);
        sortByDropDown->setObjectName("sortByDropDown");
        sizePolicy1.setHeightForWidth(sortByDropDown->sizePolicy().hasHeightForWidth());
        sortByDropDown->setSizePolicy(sizePolicy1);
        sortByDropDown->setCursor(QCursor(Qt::PointingHandCursor));
        sortByDropDown->setEditable(true);

        horizontalLayout_3->addWidget(sortByDropDown);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(searchButton);


        verticalLayout_5->addLayout(horizontalLayout_3);

        foodTable = new QTableView(centralwidget);
        foodTable->setObjectName("foodTable");

        verticalLayout_5->addWidget(foodTable);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 10);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        selectCategoryDropDown->setPlaceholderText(QCoreApplication::translate("MainWindow", "Select Category...", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
