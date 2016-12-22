#include "widget.h"
#include "ui_widget.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mDatabase.setHostName("localhost");
    mDatabase.setDatabaseName("Projektna");
    mDatabase.setPort(3306);
    mDatabase.setUserName("root");
    mDatabase.setPassword("root");

    if (!mDatabase.open()) {
        QMessageBox::critical(this, "Error", mDatabase.lastError().text());
        return;
    }

    mModel = new QSqlTableModel(this);
    mModel->setTable("Person");
    mModel->select();
    ui->tableView->setModel(mModel);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_New_clicked()
{
    mModel->insertRow(mModel->rowCount());
}

void Widget::on_Remove_clicked()
{
    mModel->removeRow(ui->tableView->currentIndex().row());
}

void Widget::on_Update_clicked()
{
    mModel->select();
}
