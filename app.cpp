#include "app.h"
#include "database.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>

template<class T>
std::string format_with_commas(T value)
{
    std::stringstream ss;
    ss.imbue(std::locale(""));
    ss << std::fixed << value;
    return ss.str();
}

app::app(QWidget *parent) : QMainWindow(parent), ui(new Ui::appClass)
{
    ui->setupUi(this);

    /* > Events < */

    // QListWidget
    connect(ui->listWidget, &QListWidget::currentItemChanged, this, &app::list_selection_changed);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &app::filter_changed);
    

    /* Window Theme / Other (ignore) */
    QPixmap title_market("assets\\market.png");
    ui->title_market->setPixmap(title_market.scaled(200, 50, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation));
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    /* Add to list */

    QDir path("assets\\name");
    path.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    items = path.entryList();
    ui->listWidget->addItems(Database::GetInstance()->get());
}

void app::list_selection_changed()
{
    std::string selected_name = ui->listWidget->currentItem()->text().toStdString();
    Item* item = Database::GetInstance()->obj_from_name(selected_name);

    std::string filename = "assets\\items\\" + item->bsgid;
    QPixmap selection_ico(filename.c_str());
    if (!selection_ico.isNull())
    {
        ui->img_selecteditem->setPixmap(selection_ico.scaled(75, 75, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation));
    }
    else
    {
        QPixmap error_ico("assets\\error.jpg");
        ui->img_selecteditem->setPixmap(error_ico.scaled(75, 75, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation));
    }

    std::string price = "average price (24hrs): $" + format_with_commas(item->price);
    ui->iteminfo_price->setText(price.c_str());

    std::string uid = "uid: " + item->uid;
    ui->iteminfo_uid->setText(uid.c_str());

    std::string bsgId = "bsgid: " + item->bsgid;
    ui->iteminfo_bsgid->setText(bsgId.c_str());
    
}

void app::filter_changed(const QString &arg1)
{
    QRegularExpression reg(arg1, QRegularExpression::PatternOption::CaseInsensitiveOption);
    ui->listWidget->blockSignals(true);
    ui->listWidget->clear();
    ui->listWidget->blockSignals(false);
    ui->listWidget->addItems(Database::GetInstance()->get().filter(reg));
}
