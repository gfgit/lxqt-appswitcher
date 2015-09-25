#pragma once

#include <QListWidget>
#include <QVBoxLayout>
#include <X11/Xlib.h>

namespace GlobalKeyShortcut
{ class Action; }

class AppSwitcher: public QListView
{
    Q_OBJECT
public:
    AppSwitcher(QWidget *parent);
protected:
    virtual void currentChanged(const QModelIndex &current, const QModelIndex &previous);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    void showSwitcher();
    void selectNextItem();
private:
    GlobalKeyShortcut::Action *m_globalShortcut;
    int m_current = 0;
};
