#ifndef APP_H
#define APP_H

#include <QtWidgets/QMainWindow>
#include "ui_app.h"

#include <qdir.h>
#include <qdebug.h>
#include <qregularexpression.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class app : public QMainWindow
{
    Q_OBJECT

public:
    app(QWidget *parent = Q_NULLPTR);

private slots:
    void list_selection_changed();
    void filter_changed(const QString& arg1);

private:
    Ui::appClass *ui;

    QStringList items;
};

#endif // APP_H