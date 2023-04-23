#include "random_crit.h"
#include "ui_random_crit.h"

Random_crit::Random_crit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Random_crit)
{
    ui->setupUi(this);

    ui->n->setMinimum(m);
    ui->m->setMinimum(1);
    ui->eps->setMinimum( numeric_limits<double>::epsilon());
    ui->delta->setMinimum( numeric_limits<double>::epsilon());
    ui->p->setMinimum( numeric_limits<double>::epsilon());

    ui->n->setMaximum(INFINITY);
    ui->m->setMaximum(1000);

    ui->n->setValue(1000);
    ui->m->setValue(m);
    ui->eps->setValue(eps);
    ui->delta->setValue(delta);
    ui->p->setValue(p);
}

Random_crit::~Random_crit()
{
    delete ui;
}

void Random_crit::slot(Opt_fun *opt_fun_, Dom *dom_)
{
  opt_fun=opt_fun_;
  dom=dom_;
}

void Random_crit::on_plot_button_clicked()
{
    try{
    n=1000;
    eps=ui->eps->value();
    delta=ui->delta->value();
    p=ui->p->value();
    m=ui->m->value();

    if(ui->inc_rb->isChecked())
        stop_crit = new Stop_crit_random_search_dif(n, eps); else
            stop_crit = new Stop_crit_random_search_last_change(n,m);

    rs = new Random_search(dom, opt_fun, stop_crit,delta,p);







    hm=new HeatMap(dom,opt_fun,rs);

    }catch (const std::exception& e) {
               QMessageBox::warning(this, "Exception", e.what());
           }
}


void Random_crit::on_n_valueChanged(int arg1)
{
    ui->m->setMaximum(arg1);
}


void Random_crit::on_m_valueChanged(int arg1)
{
        ui->n->setMinimum(arg1);
}

