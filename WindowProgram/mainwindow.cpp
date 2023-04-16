
#include "mainwindow.h"
#include "RBTree.h"
#include "Food.h"
#include <QStringList>
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Initialize the Combo Box
    m_combo_box = new QComboBox(this);

    // Populate the Combo Box with the keys of the red black tree
    std::string fileName = "food.csv"; // File name
    std::vector<Food> foods = loadFromFile(fileName); // vector to hold all Food instances

    RBTree tree;

    for (const auto& food : foods) {
        tree.insert(food);
    }

    QStringList combo_box_items;
    auto keys = tree.uniqueKeys();
    for (auto key : keys) {
        combo_box_items << QString::fromStdString(key);
    }
    m_combo_box->addItems(combo_box_items);

    // Create the search button
    m_search_button = new QPushButton("Search", this);
    m_search_button->setFixedSize(80, 30);

    // Connect the clicked signal to a slot that will perform the search
    connect(m_search_button, &QPushButton::clicked, this, [this]() {
        // TODO: Perform the search and display the results
    });

    // Add the search button to the main window
    layout()->addWidget(m_search_button);


    // Add the Combo Box to the main window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_combo_box);
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete m_combo_box;
}


