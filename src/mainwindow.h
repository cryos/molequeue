/******************************************************************************

  This source file is part of the MoleQueue project.

  Copyright 2011 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QSystemTrayIcon>
#include <QtNetwork/QLocalSocket>

class QAction;
class QIcon;
class QLocalServer;

namespace Ui {
class MainWindow;
}

namespace MoleQueue {

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();

  void setVisible(bool visible);

protected:
  void closeEvent(QCloseEvent *event);

private slots:
  void setIcon(int index);
  void iconActivated(QSystemTrayIcon::ActivationReason reason);
  void showMessage();
  void messageClicked();
  void newConnection();
  void socketReadyRead();
  void socketError(QLocalSocket::LocalSocketError socketError);
  void socketConnected();
  void removeServer();

  /** Move file to appropriate place for execution. */
  void moveFile();

private:
  void createIconGroupBox();
  void createMessageGroupBox();
  void createActions();
  void createMainMenu();
  void createTrayIcon();

  /** Our MainWindow GUI. */
  Ui::MainWindow *m_ui;

  QAction *m_minimizeAction;
  QAction *m_maximizeAction;
  QAction *m_restoreAction;
  QAction *m_quitAction;

  QIcon *m_icon;
  QSystemTrayIcon *m_trayIcon;
  QMenu *m_trayIconMenu;

  QLocalServer *m_server;

  bool m_removeServer;
};

} // End namespace

#endif
