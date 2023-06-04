#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>
#include "BinaryTree.h"

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
    void on_insert_btn_clicked();

    void on_search_btn_clicked();

    void on_del_btn_clicked();

    void on_pushButton_clicked();

    void on_preOrder_btn_clicked();

    void on_del_tree_btn_clicked();

    void on_simOrder_btn_clicked();

    void on_postOrder_btn_clicked();

private:
    Ui::MainWindow *ui;
    BinaryTree T;
    QGraphicsScene* CreateScene(Tree*);
    void clear_status();
};
#endif // MAINWINDOW_H
