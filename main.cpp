#include "app.h"
#include <QtWidgets/QApplication>

#include "database.h"

int main(int argc, char *argv[])
{
    Database::GetInstance()->populate_db();

    QApplication a(argc, argv);
    app w;
    w.show();
    return a.exec();
}
