#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"

QString baseUrl = "https://opensea.io/assets/matic/0xbc2c896a0ed6fa05e35ac823c1ec8cd7e324b5e4";
const int TOTAL_DURATION = 210;
const int INTERVAL = 100;
int SCREEN_WIDTH;
int SCREEN_HEIGHT;
QStringList commentForPicking;

int curPicker = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QScreen *screen =  QApplication::primaryScreen();
    SCREEN_WIDTH = screen->geometry().width();
    SCREEN_HEIGHT = screen->geometry().height();
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));

    commentForPicking.append("Checking sell status");
    commentForPicking.append("Clicking sell button");
    commentForPicking.append("Clicking duration calendar");
    commentForPicking.append("Clicking date range");
    commentForPicking.append("Clicking 6 months");
    commentForPicking.append("Clicking outside");
    commentForPicking.append("Clicking Complete listing");
    commentForPicking.append("Clicking Metamask scroll down");
    commentForPicking.append("Clicking Metamask scroll sign");

    QString initalPts = ui->initalPts->toPlainText();
    QStringList pts = initalPts.split('\n');
    for (int i = 0; i < pts.length(); i++){
        int x = pts[i].split(',')[0].toInt();
        int y = pts[i].split(',')[1].toInt();
        ptArray[i] = QPoint(x, y);
    }
//    ptArray[0] = QPoint(820,379);
//    ptArray[1] = QPoint(1033,162);
//    ptArray[2] = QPoint(187,331);
//    ptArray[3] = QPoint(274,399);
//    ptArray[4] = QPoint(216,529);
//    ptArray[5] = QPoint(61,365);
//    ptArray[6] = QPoint(207, 478);
//    ptArray[7] = QPoint(1553,519);
//    ptArray[8] = QPoint(1465,580);

    ui->pickPosButton->setText(QString("Pick Position for %1").arg(commentForPicking.at(0)));
}
void MainWindow::onTimer()
{
    curTimer ++;
    if (curTimer % 10 == 0)
        qDebug() << "step -> "<< (curTimer % TOTAL_DURATION);
    switch (curTimer % TOTAL_DURATION) {
    case 0:
        curNftId++;
        while (isRegistered(curNftId)){ curNftId ++;}
        qDebug() << "current NFT Id -> "<<  curNftId;
        ui->label->setText(QString("%1").arg(curNftId));
        openUrl(QUrl(QString("%1/%2").arg(baseUrl).arg(curNftId)));
        break;

    case 60:
        if (isSellingStatus()) {
            curTimer -= curTimer % TOTAL_DURATION - 10;
            triggerCloseViaCtrlW();
        }
        triggerClick(ptArray[1]);
        break;
    case 100:
        triggerWriteViaCtrlV("0.0042");
        break;
    case 101:
        triggerClick(ptArray[2]);
        break;
    case 102:
        triggerClick(ptArray[3]);
        break;
    case 103:
        triggerClick(ptArray[4]);
        break;
    case 104:
        triggerClick(ptArray[5]);
        break;
    case 105:
        triggerClick(ptArray[6]);
        break;
    case 180:
        triggerClick(ptArray[7]);
        break;
    case 181:
        triggerClick(ptArray[8]);
        break;
    case 205:
        triggerCloseViaCtrlW();
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    qDebug() <<INTERVAL * ui->spdSync->text().toFloat();
    timer->stop();
    timer->start(INTERVAL * ui->spdSync->text().toFloat());
    return;
    int x = (int)(65536.0 / 1920 * 500 - 1); //convert to absolute coordinates
    int y = (int)(65536.0 / 1080 * 500 - 1);

}

void MainWindow::openUrl (QUrl url) {
//    QDesktopServices::openUrl(QUrl("https://opensea.io/assets/matic/0xbc2c896a0ed6fa05e35ac823c1ec8cd7e324b5e4/629"));
    QDesktopServices::openUrl(url);
}

bool MainWindow::isSellingStatus() {
    QScreen *screen =  QApplication::primaryScreen();// init screen first (application.primaryScreen();)
    QPixmap pixmap = screen->grabWindow(0, ptArray[0].x(), ptArray[0].y(), 10,10);
    if (pixmap.toImage().pixel(0, 0) == 4280442523)
        return true;
    return false;


}
bool MainWindow::isRegistered(int id) {
    if (id < ui->startNftId->text().toInt())
        return true;
    int registered[167] = {0,1,2,3,4,5,6,7,8,9,10,31,32,33,36,37,38,39,40,42,43,44,45,47,51,52,55,56,57,60,62,68,69,70,72,74,77,79,80,81,82,83,84,88,89,90,91,92,93,94,95,96,97,98,100,101,102,110,111,112,114,115,116,117,118,120,121,122,123,124,127,128,129,171,174,175,176,177,179,181,183,184,185,186,187,188,189,355,358,363,415,419,492,551,553,556,558,561,624,626,627,629,631,632,643,646,649,654,672,695,720,728,730,732,1278,1581,1745,1805,1819,1958,1981,2141,2907,2917,2986,3051,3053,3060,3063,3064,3065,3067,3109,3110,3111,3113,3115,3410,3602,3604,3606,3611,3613,3619,3620,3622,3627,3649,3652,3672,3757,3840,3975,3995,4004,4148,4453,4962,5555,6513,6795,6806,6868,7235,7236,7237,7330};
    for (int i= 0 ; i < 166; i++)
        if (registered[i] == id)
            return true;
    return false;
}


void MainWindow::on_pickPosButton_clicked()
{
    ptArray[curPicker ++] = QCursor::pos();
    ui->statusBar->showMessage(QString("%1 : %2").arg(QCursor::pos().x()).arg(QCursor::pos().y()));
    if (curPicker < commentForPicking.length()){
        ui->pickPosButton->setText(QString("Pick Position for %1").arg(commentForPicking.at(curPicker)));
    }
    else{
        ui->pickPosButton->setText("Done! You can start timer.");
        curPicker = 0;
    }

}
void MainWindow::triggerClick(QPoint pt) {
    mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE
                , 65535 * pt.x() / SCREEN_WIDTH,65535 * pt.y() / SCREEN_HEIGHT, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, 0,0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, 0,0, 0, 0);
}

void MainWindow::triggerWriteViaCtrlV(QString str) {
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(str);

    keybd_event(VK_CONTROL, 0x1D, KEYEVENTF_EXTENDEDKEY | 0, 0);
    keybd_event('V', 0x2F, KEYEVENTF_EXTENDEDKEY | 0, 0);
    keybd_event('V', 0x2F, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0x1D, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

void MainWindow::triggerCloseViaCtrlW() {
    keybd_event(VK_CONTROL, 0x1D, KEYEVENTF_EXTENDEDKEY | 0, 0);
    keybd_event('W', 0x2F, KEYEVENTF_EXTENDEDKEY | 0, 0);
    keybd_event('W', 0x2F, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0x1D, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}
