#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>

struct Object {
    int id;
    QString name;
};


class model : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit model(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    Q_SLOT void addObject(const int id, const QString &name);
private:
    QList<Object> m_objects;
    QHash<int, QByteArray> roleNames() const;
};

#endif // MODEL_H
