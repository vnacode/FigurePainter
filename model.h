#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include <figure.h>
#include <QItemSelection>

class model : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit model(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    void clearAll();
    void clearSelected();
    QModelIndex getItemIndex(QGraphicsItem *item);
    Q_SLOT void addFigure(Figure *figure);
    Q_SLOT void changeSelection(const QItemSelection &selected, const QItemSelection &deselected);
private:
    QList<Figure*> m_objects;
};

#endif // MODEL_H
