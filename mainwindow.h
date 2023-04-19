#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QDesktopWidget>
#include <QPixmap>
#include <QScreen>
#include <QUrl>
#include <QDesktopServices>
#include <QClipboard>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    QTimer *timer;
    int curTimer = -50;
    const int nftCnt = 7777;
    int curNftId = 0;
    QPoint ptArray[100];

    void openUrl (QUrl url);
    void triggerClick(QPoint pt);
    void triggerWriteViaCtrlV(QString str);
    void triggerCloseViaCtrlW();

    bool isSellingStatus();
    bool isRegistered(int id);

public slots:
    void onTimer();
private slots:
    void on_pushButton_clicked();
    void on_pickPosButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
