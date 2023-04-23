#include "Heatmap.h"

HeatMap::HeatMap() {

}

HeatMap::~HeatMap()
{
    delete image;
    if (opt_method != nullptr) {
        delete opt_method;
        opt_method = nullptr;
    }

    if (dom != nullptr) {
        delete dom;
        dom = nullptr;
    }

    if (opt_fun != nullptr) {
        delete opt_fun;
        opt_fun = nullptr;
    }
}

void HeatMap::mousePressEvent(QMouseEvent *event){


    vector<double> left = dom->get_left();
    vector<double> right = dom->get_right();

    vector<double>x_0={((event->pos().x())*(right[0]-left[0]))/width+left[0],(1-(double((event->pos().y()))/height))*(right[1]-left[1])+left[1]};

    vector<vector<double>> X_n=opt_method->optim(x_0);


    vector<vector<int>> x_coord{};

    for (vector<double> v:X_n) {
        x_coord.push_back({
                              (int) (width * (v[0] - left[0]) / (right[0] - left[0])),
                              height - (int) (height * (v[1] - left[1]) / (right[1]- left[1]))
                          });
    }


    QPixmap Frame = mainFrame;
    QPainter p(&Frame);
    p.setPen(Qt::blue);


    for(unsigned i=0;i<x_coord.size()-1;++i)
        p.drawLine(x_coord[i][0],x_coord[i][1],x_coord[i+1][0],x_coord[i+1][1]);

    p.drawText(QPointF(x_coord[0][0],x_coord[0][1]), ("start..."));
    p.drawText(QPointF(x_coord[x_coord.size()-1][0],x_coord[x_coord.size()-1][1]), ("...finish!"));

    p.end();

    this->setPixmap(Frame);
    this->show();

}


HeatMap::HeatMap(Dom * dom, Opt_fun * opt_fun)
{
    set(dom,opt_fun);
}

HeatMap::HeatMap(Dom * dom_, Opt_fun * of, Opt_method * om): dom(dom_), opt_fun(of), opt_method(om)
{
    set(dom,opt_fun);
};

void HeatMap::set(Dom * dom, Opt_fun * opt_fun)
{



    vector<double> temp{};

    vector<double> left = dom->get_left();
    vector<double> right = dom->get_right();

    double step_w = (right[0] - left[0]) / width;
    double step_h = (right[1]-left[0]) / height;
    double pos_h = right[1];
    double pos_w = left[0];

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            temp.push_back(opt_fun->calc(vector<double>{pos_w, pos_h}));
            pos_w += step_w;
        }
        map.push_back(temp);
        temp.clear();
        pos_w =left[0];
        pos_h -= step_h;
    }

    double max = map[0][0];
    double min = map[0][0];

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j) {
            if(map[i][j] > max) max = map[i][j];
            if(map[i][j] < min) min = map[i][j];
        }
    };
    if(image)
        delete image;
    image = new QImage(width, height, QImage::Format_RGB32);

    int Rv = 0;

    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
                Rv = (int) (256 * (map[i][j] - min) / (max - min));
                QRgb value = qRgb(200, 0, Rv);
                image->setPixel(j, i, value);
        }
    };

    resize(width, height);

    mainFrame = QPixmap::fromImage(*image);



    this->setPixmap(mainFrame);

    this->show();
}


