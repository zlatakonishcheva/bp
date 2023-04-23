#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMessageBox>

#include"newton_crit.h"
#include"random_crit.h"

#include"opt_method.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:

    void on_crit_button_clicked();

    void on_right_1_valueChanged(double arg1);

    void on_left_1_valueChanged(double arg1);

    void on_right_2_valueChanged(double arg1);

    void on_left_2_valueChanged(double arg1);

private:
    Ui::MainWidget *ui;

    double left_1 = -2;
    double left_2 = -2;
    double right_1 = 2;
    double right_2 = 2;

    Newton_crit *Newton_c;
    Random_crit *Random_c;

    Opt_fun *opt_fun;
    Dom *dom;


signals:
    void signal(Opt_fun*, Dom*);
};
#endif // MAINWIDGET_H
