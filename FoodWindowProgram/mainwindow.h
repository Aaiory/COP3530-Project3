/* Window Icon:  https://openclipart.org/detail/289282/fast-food-icon */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStandardItemModel>
#include <chrono>
#include "../FoodFinder.h"
#include "../RBTree.h"
#include "../HMap.h"
#include "../Food.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *m_tableModel;
    QPushButton *m_search_button;
    FoodFinder m_foodFinder; // Add this line to declare m_foodFinder
    void populateTable(const std::vector<std::vector<QString>>& data);
    void clearTable();
    std::vector<std::vector<QString>> getQTableValues(std::vector<Food> foodVector);
};

#endif // MAINWINDOW_H
