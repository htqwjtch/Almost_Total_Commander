#ifndef COLORDELEGATE_H
#define COLORDELEGATE_H

#include <QApplication>
#include <QColor>
#include <QFileSystemModel>
#include <QMimeDatabase>
#include <QPainter>
#include <QProcess>
#include <QStyledItemDelegate>
#include <QTableView>

class ColorDelegate : public QStyledItemDelegate
{
    Q_OBJECT
  public:
    ColorDelegate(QObject *parent = nullptr);

    void paint(QPainter *, const QStyleOptionViewItem &, const QModelIndex &) const override;

  private:
    QColor classifyFileColor(const QFileInfo &) const;

  private:
    QMap<QString, QString> colorMap;
};

#endif // COLORDELEGATE_H
