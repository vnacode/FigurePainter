#include "model.h"

model::model(QObject *parent)
    : QAbstractListModel(parent)
{
}


int model::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return  m_objects.length();
}

QVariant model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role ==  Qt::DisplayRole)
        return m_objects[index.row()]->getFigureName() + " "+ QString::number(m_objects[index.row()]->getId());

    return QVariant();
}

bool model::removeRows(int row, int count, const QModelIndex &parent)
{
    if (m_objects.count() < row || count < 1)
        return false;
    beginRemoveRows(parent, row, row + count - 1);
    for (int i = 0; i < count; i++)
    {
        m_objects.takeAt(row)->deleteLater();
    }
    endRemoveRows();
    return true;
}

void model::clearAll()
{
    removeRows(0,m_objects.count());
}

void model::clearSelected()
{
    for (auto *f : m_objects)
    {
        if (f->isSelected())
        {
           removeRows(m_objects.indexOf(f), 1);
        }
    }
}

QModelIndex model::getItemIndex(QGraphicsItem *item)
{
    return index(m_objects.indexOf(static_cast<Figure*>(item)));
}


void model::addFigure(Figure *figure)
{
    if (figure->getId() <= 0)
        return;
    for (auto &o : m_objects)
    {
        if (o->getId() == figure->getId())
            return;
    }
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_objects << figure;
    endInsertRows();
}

void model::changeSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    for (auto &i : selected.indexes())
    {
        m_objects[i.row()]->setSelected(true);
    }
    for (auto &i : deselected.indexes())
    {
        m_objects[i.row()]->setSelected(false);
    }
}


