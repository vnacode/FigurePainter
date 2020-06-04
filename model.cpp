#include "model.h"

model::model(QObject *parent)
    : QAbstractListModel(parent)
{
}


int model::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return  m_objects.length();
}

QVariant model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role ==  Qt::DisplayRole)
        return m_objects[index.row()].name + " "+ QString::number(m_objects[index.row()].id);

    // FIXME: Implement me!
    return QVariant();
}

bool model::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}

QHash<int, QByteArray> model::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "object";
        return roles;
}
#include <qdebug.h>

void model::addObject(const int id, const QString &name)
{
    if (name.isEmpty() && id <= 0)
        return;
    for (auto &o : m_objects)
    {
        if (o.id == id)
            return;
    }
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_objects << Object({id, name});
    endInsertRows();
        qDebug() << "Adding new object " << id << name;
}
