#ifndef RAWITEM_H
#define RAWITEM_H

#include "graphicsitem.h"

namespace Gerber {
class File;
}

class RawItem : public GraphicsItem {
public:
    RawItem(const Path& path, Gerber::File* file);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    int type() const override;
    Paths paths() const override;
    QPainterPath shape() const override;

protected:
    QPolygonF m_polygon;
    const Path& m_path;
    mutable QPainterPath m_shape_raw;
    mutable double m_scale = std::numeric_limits<double>::max();
    // QGraphicsItem interface
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // RAWITEM_H
