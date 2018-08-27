#pragma once
#include <QPushButton>

class ColorButton : public QPushButton {
  Q_OBJECT
  public:
    ColorButton(QWidget* parent);
    
    void setColor(QColor col);
    QColor getColor();
    
  signals:
    void valueChanged();
    
  protected:
    virtual void mousePressEvent(QMouseEvent* e);
    
  private:
    QColor value;
};
