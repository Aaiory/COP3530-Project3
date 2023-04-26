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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
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
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *treeTimer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *tableTimer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *selectCategoryDropDown;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *sortByDropDown;
    QVBoxLayout *verticalLayout_3;
    QComboBox *usingDS;
    QComboBox *sortByAscending;
    QPushButton *searchButton;
    QTableView *foodTable;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(635, 546);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../simplefastfoodicon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
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
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Sans Typewriter")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font1.setPointSize(12);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        treeTimer = new QLCDNumber(centralwidget);
        treeTimer->setObjectName("treeTimer");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeTimer->sizePolicy().hasHeightForWidth());
        treeTimer->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        treeTimer->setFont(font2);

        horizontalLayout_2->addWidget(treeTimer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        tableTimer = new QLCDNumber(centralwidget);
        tableTimer->setObjectName("tableTimer");
        sizePolicy1.setHeightForWidth(tableTimer->sizePolicy().hasHeightForWidth());
        tableTimer->setSizePolicy(sizePolicy1);
        tableTimer->setFont(font2);
        tableTimer->setSmallDecimalPoint(false);

        horizontalLayout->addWidget(tableTimer);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);
        label_4->setAutoFillBackground(false);

        horizontalLayout_5->addWidget(label_4);

        selectCategoryDropDown = new QComboBox(centralwidget);
        selectCategoryDropDown->setObjectName("selectCategoryDropDown");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(selectCategoryDropDown->sizePolicy().hasHeightForWidth());
        selectCategoryDropDown->setSizePolicy(sizePolicy2);
        selectCategoryDropDown->setFont(font1);
        selectCategoryDropDown->setCursor(QCursor(Qt::PointingHandCursor));
        selectCategoryDropDown->setAutoFillBackground(false);
        selectCategoryDropDown->setEditable(true);
        selectCategoryDropDown->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_5->addWidget(selectCategoryDropDown);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);
        label_5->setAutoFillBackground(false);

        horizontalLayout_4->addWidget(label_5);

        sortByDropDown = new QComboBox(centralwidget);
        sortByDropDown->setObjectName("sortByDropDown");
        sizePolicy2.setHeightForWidth(sortByDropDown->sizePolicy().hasHeightForWidth());
        sortByDropDown->setSizePolicy(sizePolicy2);
        sortByDropDown->setFont(font1);
        sortByDropDown->setCursor(QCursor(Qt::PointingHandCursor));
        sortByDropDown->setAutoFillBackground(false);
        sortByDropDown->setEditable(true);
        sortByDropDown->setInsertPolicy(QComboBox::InsertAlphabetically);
        sortByDropDown->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_4->addWidget(sortByDropDown);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        usingDS = new QComboBox(centralwidget);
        usingDS->addItem(QString());
        usingDS->addItem(QString());
        usingDS->setObjectName("usingDS");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Lucida Sans Typewriter")});
        font3.setPointSize(12);
        usingDS->setFont(font3);

        verticalLayout_3->addWidget(usingDS);

        sortByAscending = new QComboBox(centralwidget);
        sortByAscending->addItem(QString());
        sortByAscending->addItem(QString());
        sortByAscending->setObjectName("sortByAscending");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sortByAscending->sizePolicy().hasHeightForWidth());
        sortByAscending->setSizePolicy(sizePolicy3);
        sortByAscending->setFont(font3);

        verticalLayout_3->addWidget(sortByAscending);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy4);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Lucida Sans Typewriter")});
        font4.setPointSize(12);
        font4.setBold(true);
        searchButton->setFont(font4);

        verticalLayout_3->addWidget(searchButton);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_3);

        foodTable = new QTableView(centralwidget);
        foodTable->setObjectName("foodTable");
        foodTable->setToolTipDuration(-1);
        foodTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        foodTable->setDragEnabled(true);
        foodTable->setDragDropMode(QAbstractItemView::DragDrop);
        foodTable->setDefaultDropAction(Qt::MoveAction);
        foodTable->setSortingEnabled(false);
        foodTable->setWordWrap(false);
        foodTable->horizontalHeader()->setCascadingSectionResizes(true);
        foodTable->verticalHeader()->setCascadingSectionResizes(false);

        verticalLayout_5->addWidget(foodTable);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 10);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Food Finder", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Load Time:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "RB Tree:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hash Table:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Category:", nullptr));
        selectCategoryDropDown->setPlaceholderText(QCoreApplication::translate("MainWindow", "Select Category...", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Sort By:", nullptr));
        sortByDropDown->setPlaceholderText(QCoreApplication::translate("MainWindow", "Select Nutritonal Data", nullptr));
        usingDS->setItemText(0, QCoreApplication::translate("MainWindow", "RB Tree", nullptr));
        usingDS->setItemText(1, QCoreApplication::translate("MainWindow", "Hash Table", nullptr));

        sortByAscending->setItemText(0, QCoreApplication::translate("MainWindow", "Ascending", nullptr));
        sortByAscending->setItemText(1, QCoreApplication::translate("MainWindow", "Descending", nullptr));

        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
