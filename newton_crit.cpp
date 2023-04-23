#include "newton_crit.h"
#include "ui_newton_crit.h"

Newton_crit::Newton_crit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Newton_crit)
{
    ui->setupUi(this);

    //ui->n->setMinimum(1);
    ui->eps->setMinimum( numeric_limits<double>::epsilon());
    //ui->n->setMaximum(INFINITY);

    //ui->n->setValue(n);
    ui->eps->setValue(eps);

}

Newton_crit::~Newton_crit()
{
    delete ui;
}

void Newton_crit::slot(Opt_fun *opt_fun_, Dom *dom_)
{
  opt_fun=opt_fun_;
  dom=dom_;
}

void Newton_crit::on_plot_button_clicked()
{
    try{
    n=700;
    eps=ui->eps->value();

    if(ui->inc_rb->isChecked())
        stop_crit = new Stop_crit_Newton_dif(n, eps); else if(ui->grad_rb->isChecked())
        stop_crit = new Stop_crit_Newton_grad(n, eps); else if(ui->iter_rb->isChecked())
        stop_crit = new Stop_crit_count(n); else
        stop_crit = new Stop_crit_Newton3(n, eps);

    Nwtn = new Newton(dom,opt_fun,stop_crit);






    hm = new HeatMap(dom,opt_fun, Nwtn);
}catch (const std::exception& e) {
           QMessageBox::warning(this, "Exception", e.what());
       }


}

