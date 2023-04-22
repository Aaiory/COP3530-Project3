
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../RBTree.h"
#include "../Food.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Populate the Combo Box with the keys of the red black tree
    std::string fileName = "food.csv"; // File name
    std::vector<Food> foods = loadFromFile(fileName); // vector to hold all Food instances
    std::vector<std::string> categories = loadHeadersFromFile(fileName);
    categories.erase(categories.begin());

    RBTree tree;

    for (const auto& food : foods) {
        tree.insert(food);
    }

    ui->setupUi(this);

    auto keys = tree.uniqueKeys();
    for (const std::string& key : keys) {
        ui -> selectCategoryDropDown->addItem(QString::fromStdString(key));
    }
    for (const std::string& category : categories) {
        ui -> sortByDropDown -> addItem(QString::fromStdString(category));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


