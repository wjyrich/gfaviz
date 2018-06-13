#pragma once
#include "headers.h"
#include "vizsettings.h"
#include <QGraphicsTextItem>
//#include <QtWidgets/QGraphicsItem>

class VizGraph;
class VizElement;
class GfaLine;
class VizGroup;

class VizElementLabel : public QGraphicsTextItem {
  public:
    VizElementLabel(QString text, VizElement* _parent = 0);
    //virtual void setHighlight(bool val);
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    
  protected:
    VizElement* parent;
    //virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *);
    //virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *) { setHover(true); };
    //virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *) { setHover(false); };  
};

class VizElement : public QGraphicsPathItem {
  public:
    VizElement(VizGraph* _vg, GfaLine* line);
    ~VizElement();
    const QVariant getOption(VizGraphParam p) const;
    //virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void addGroup(VizGroup* group);
    VizElementLabel* labelItem;
    
  protected:
    VizGraph* vg;
    VizGraphSettings settings;
    void drawLabel();
    virtual QPointF getCenterCoord() = 0;
    virtual GfaLine* getGfaElement() = 0;
    
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    vector<VizGroup*> groups;
    
  private:
    

};

