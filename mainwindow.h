#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QStringList>
#include <QString>
#include <QLabel>
#include <QSaveFile>
#include <QDesktopServices>
#include <QTextStream>
#include <QFileSelector>
#include <QTextEdit>
#include <QFont>
#include <QColorDialog>
#include <QMenu>
#include <QWidget>
#include <QListWidget>
#include <QFontDialog>
#include <QtWidgets>
#include <QCheckBox>
#include <QVector>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#if defined(Q_OS_WIN)
    #define qUsername QString::fromLocal8Bit (qgetenv ("USERNAME").constData ()).toUtf8 ()
#elif defined(Q_OS_UNIX)
    #define qUsername qgetenv("USER").constData ()
#endif

class MainWindow : public QMainWindow
{
    Q_OBJECT
    const int MAX_H = 1024;
    const int MAX_W = 1280;

    const int START_H = 800;
    const int START_W = 1024;

    const int MIN_H = 600;
    const int MIN_W = 800;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel *history;
    QLabel *WordSearchLabel;
    QLabel *labelPlus;
    QLabel *labelMinus;
    QPushButton *showD;
    QPushButton *plus;
    QPushButton *minus;
    QPushButton *italicBtn;
    QPushButton *boldBtn;
    QPushButton *underlineBtn;
    QPushButton *changeColor;
    QLabel *label;
    QTextEdit *inputT;
    int fSize;
    QListWidget *files;
    QTextEdit *search;
    QPushButton *searchBtn;
    QCheckBox *checkWordRegicst;
    QCheckBox *searchAll;
    QPushButton *hoverOnOff;
    QPushButton *BookWords;
    QSlider *slider;
    QLabel *labelSizeInterval;
private slots:
    void save();
    void plusText();
    void minusText();
    void setItalic();
    void setBold();
    void setUnderline();
    void setColor();
//    void changeColorMainWindow();
    void closeapp();
    void openFile();
    void itemSelected(QListWidgetItem *item);
    void chooseYourFont();
    void saveFilesHistory();
    void ReadFilesHistory();
    void fromStringToListItem(QString filepath);
    void searchWord();
    void checkRegisterWords();
    void hoverOnOrOff();
    void checkgramary();
    QVector<QString> convertFromStirngToStringVector(QString str);
    void chooseHeightLine();
private:
    Ui::MainWindow *ui;

    void resizeEvent(QResizeEvent *e) override;
};
#endif // MAINWINDOW_H
