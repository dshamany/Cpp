#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
{
    ui->setupUi(this);
    ui->textEdit->setFocus();
    ui->dateEdit->setDate(QDate::currentDate());
    currentDate = ui->dateEdit->date();
    loadData();
}

void MainView::saveData()
{
    QFile file(currentDate.toString());
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText() << '\n';
    }
}

void MainView::loadData()
{
    QFile file(currentDate.toString());
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        ui->textEdit->setText(stream.readAll());
    }
    else
    {
        ui->textEdit->setText("");
    }
}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_dateEdit_dateChanged(const QDate &date)
{
    saveData();
    currentDate = date;
    loadData();
}
