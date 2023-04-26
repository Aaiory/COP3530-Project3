#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_tableModel(new QStandardItemModel(this))
    , m_foodFinder("food.csv") // Initialize m_foodFinder
{
    // Populate the Combo Box with the keys of the red black tree
    std::string fileName = "food.csv"; // File name
    FoodFinder foodFinder(fileName);
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
        ui->selectCategoryDropDown->addItem(QString::fromStdString(key));
    }
    for (const std::string& category : categories) {
        ui->sortByDropDown->addItem(QString::fromStdString(category));
    }

    // Set up table view
    m_tableModel->setColumnCount(categories.size());
    QStringList headerLabels;
    for (const auto& category : categories) {
        headerLabels.append(QString::fromStdString(category));
    }
    m_tableModel->setHorizontalHeaderLabels(headerLabels);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_tableModel;
}

void MainWindow::clearTable()
{
    m_tableModel->removeRows(0, m_tableModel->rowCount());
}

void MainWindow::populateTable(const std::vector<std::vector<QString>>& data)
{
    for (const auto& row : data) {
        QList<QStandardItem *> items;
        for (const auto& item : row) {
            items.append(new QStandardItem(item));
        }
        m_tableModel->appendRow(items);
    }

    ui->foodTable->setModel(m_tableModel);
}

std::vector<std::vector<QString>> MainWindow::getQTableValues(std::vector<Food> foodVector){
    std::vector<std::vector<QString>> data;
    for (const auto& food : foodVector) {
        std::vector<QString> row;
        row.push_back(QString::fromStdString(food.getDescription()));
        row.push_back(QString::number(food.getNdbsNumber()));
        row.push_back(QString::number(food.getAlphaCarotene()));
        row.push_back(QString::number(food.getBetaCarotene()));
        row.push_back(QString::number(food.getBetaCryptoxanthin()));
        row.push_back(QString::number(food.getCarbohydrate()));
        row.push_back(QString::number(food.getCholesterol()));
        row.push_back(QString::number(food.getCholine()));
        row.push_back(QString::number(food.getFiber()));
        row.push_back(QString::number(food.getLuteinZeaxanthin()));
        row.push_back(QString::number(food.getLycopene()));
        row.push_back(QString::number(food.getNiacin()));
        row.push_back(QString::number(food.getProtein()));
        row.push_back(QString::number(food.getRetinol()));
        row.push_back(QString::number(food.getRiboflavin()));
        row.push_back(QString::number(food.getSelenium()));
        row.push_back(QString::number(food.getSugarTotal()));
        row.push_back(QString::number(food.getThiamin()));
        row.push_back(QString::number(food.getWater()));
        row.push_back(QString::number(food.getMonoFat()));
        row.push_back(QString::number(food.getPolyFat()));
        row.push_back(QString::number(food.getSatFat()));
        row.push_back(QString::number(food.getTotalFat()));
        row.push_back(QString::number(food.getCalcium()));
        row.push_back(QString::number(food.getCopper()));
        row.push_back(QString::number(food.getIron()));
        row.push_back(QString::number(food.getMagnesium()));
        row.push_back(QString::number(food.getPhosphorus()));
        row.push_back(QString::number(food.getPotassium()));
        row.push_back(QString::number(food.getSodium()));
        row.push_back(QString::number(food.getZinc()));
        row.push_back(QString::number(food.getVitaminARAE()));
        row.push_back(QString::number(food.getVitaminB12()));
        row.push_back(QString::number(food.getVitaminB6()));
        row.push_back(QString::number(food.getVitaminC()));
        row.push_back(QString::number(food.getVitaminE()));
        row.push_back(QString::number(food.getVitaminK()));
        data.push_back(row);
    }
    return data;
}

void MainWindow::on_searchButton_clicked()
{
    // Get the selected sort category and sort key
    std::string sortCategory = ui->selectCategoryDropDown->currentText().toStdString();
    std::string sortByKey = ui->sortByDropDown->currentText().toStdString();

    // Perform the search and get the vector of matching Food objects
    std::vector<Food> sortedVector;

    // Declare start and stop
    std::chrono::high_resolution_clock::time_point start, stop;

    if (ui->usingDS->currentText().toStdString() == "RB Tree"){
        if (ui->sortByAscending->currentIndex() == 1){
            start = std::chrono::high_resolution_clock::now();
            sortedVector = m_foodFinder.searchTreeNutrientAsc(sortCategory, sortByKey);
            stop = std::chrono::high_resolution_clock::now();
        }
        else {
            start = std::chrono::high_resolution_clock::now();
            sortedVector = m_foodFinder.searchTreeNutrientDesc(sortCategory, sortByKey);
            stop = std::chrono::high_resolution_clock::now();
        }
    }
    else {
        if (ui->sortByAscending->currentIndex() == 1){
            start = std::chrono::high_resolution_clock::now();
            sortedVector = m_foodFinder.searchMapNutrientAsc(sortCategory, sortByKey);
            stop = std::chrono::high_resolution_clock::now();
        }
        else{
            start = std::chrono::high_resolution_clock::now();
            sortedVector = m_foodFinder.searchMapNutrientDesc(sortCategory, sortByKey);
            stop = std::chrono::high_resolution_clock::now();
        }
    }

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // Convert the duration to a QString
    QString durationString = QString::number(duration.count());

    if (ui->usingDS->currentText().toStdString() == "RB Tree"){
        // Display the duration in the Qt LCD Number widget for RB Tree
        ui->treeTimer->display(durationString);
    }
    else{
        // Display the duration in the Qt LCD Number widget for Hash Table
        ui->tableTimer->display(durationString);
    }


    // Convert the search results to a vector of vector of QStrings
    std::vector<std::vector<QString>> data = getQTableValues(sortedVector);

    // Clear the table
    clearTable();

    // Populate the table with the search results
    populateTable(data);
}

