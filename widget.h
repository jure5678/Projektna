#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class Widget;
}

class QSqlTableModel;


class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_New_clicked();

    void on_Remove_clicked();

    void on_Update_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *mModel;
    QSqlDatabase mDatabase;

};

#endif // WIDGET_H
