#include "widget.h"



widget::widget(QWidget *parent) :
    QWidget(parent)

{

    layout = new QVBoxLayout(this);
    //layout->setParent(this);
}

widget::~widget()
{
    for(int i = 0; i < layer.size(); i++){
        delete layer[i];
    }

}

void widget::addLayer(QString label)
{
    layer.append(new Layer(this));
    layer[layer.size() -1]->setLabel(label);
    layout->addWidget(layer[layer.size()-1]);
}

int widget::countLayer()
{
    return layer.size();
}

QString widget::labelAt(int i)
{
    QString result = "";

    if(i < layer.size()){
        result = layer[i]->getLabel();
    }
    return result;
}

QString widget::lineEditAt(int i)
{
    QString result = "";

    if( i < layer.size()){
        result = layer[i]->getLineEdit();
    }
    return result;
}

int widget::find(QString label)
{
    int num = - 1;
  for(int i = 0; i < layer.size(); i++){
      if(layer[i]->getLabel() == label){
          num = i;
      }
  }
  return num;
}
