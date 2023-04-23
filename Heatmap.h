#ifndef OPTIMISER_HEATMAP_H
#define OPTIMISER_HEATMAP_H

#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QWidget>
#include <Qt>
#include <qpainter.h>
#include <QMouseEvent>

#include"opt_method.h"

class HeatMap : public QLabel {
public:
    HeatMap();
    HeatMap(Dom*, Opt_fun*);
    HeatMap(Dom*, Opt_fun*,Opt_method*);
    void set(Dom*, Opt_fun*);
    ~HeatMap();


protected:
    void mousePressEvent(QMouseEvent* event);

private:

    Dom *dom=nullptr;
    Opt_fun *opt_fun=nullptr;
    Opt_method *opt_method=nullptr;


    QImage* image = nullptr;
    QPixmap mainFrame;
    int width = 580, height = 580;
    vector<vector<double>> map {};
};


#endif //OPTIMISER_HEATMAP_H
