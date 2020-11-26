#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QDate>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class MainView : public QMainWindow
{
    Q_OBJECT
    QDate currentDate;
public:
    MainView(QWidget *parent = nullptr);
    ~MainView();
    void saveData();
    void loadData();
private slots:
    void on_dateEdit_dateChanged(const QDate &date);

//    void on_dateEdit_editingFinished();

//    void on_textEdit_textChanged();

private:
    Ui::MainView *ui;
};
#endif // MAINVIEW_H
