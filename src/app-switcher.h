/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXDE-Qt - a lightweight, Qt based, desktop toolset
 * https://lxqt.org/
 *
 * Copyright: 2015 LXQt team
 * Authors:
 *   zjesclean@gmail.com
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#pragma once

#include <QListWidget>
#include <QVBoxLayout>
#include <X11/Xlib.h>

namespace GlobalKeyShortcut {
class Action;
}

class AppItemDelegate;

class AppSwitcher : public QListView
{
    Q_OBJECT
public:
    AppSwitcher(QWidget* parent);

    void showSwitcher(bool forward = true);

    void setOrientation(Qt::Orientation orientation, bool force = false);

    Qt::Orientation calculateBestOrientation();

protected:
    void keyReleaseEvent(QKeyEvent *e) override;
    void closeEvent(QCloseEvent *e) override;
    void resizeEvent(QResizeEvent *e) override;

private:
    void selectItem(bool forward = true);
    void timer();
    void activateWindow(WId id);

private:
    GlobalKeyShortcut::Action* m_globalShortcut;
    GlobalKeyShortcut::Action* m_globalRShortcut;
    QTimer*                    m_timer;
    int                        m_current = 0;
    AppItemDelegate*           m_delegate = nullptr;
    Qt::Orientation            m_orientation = Qt::Vertical;
};
