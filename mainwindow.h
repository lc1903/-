#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <string>
#include <QPaintEvent>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct lrc
{
    int time;
    char lrc[512];
}LRC;

typedef struct str
{
    int i;
    int flag;
    int flag_h;
    int flag_b;
    int flag_style;
    char *gequ[64];  //song
    int currentrow;
    bool qiege; //change
    char current_gequ[128];//current_song
    bool pause;
    bool pre;
    bool next;
    bool mute;
    int volume_value;
    int volume_current;
    int volume_current1;
    bool volume;
    float time_current;
    float time_full;
    int percent_pos;
    bool back;
    bool front;
    bool seek;
    int seek_value;

    long len;
    LRC *lrc;
    char *geci[512]; //lyric
    char *arr[64];
    int row;
    map<int, string> geci1; //lyric01
    vector<int> v;
}STR;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_pre_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_front_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_mute_clicked();

    void on_volume_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

};

void *deal_fun(void *arg);
void *deal_fun2(void *arg);
void get_song(char **gequ1);
void *my_geci(void *arg);
void get_lrc(void);
void my_qiege(void);
void set_lrc(void);

#endif // MAINWINDOW_H













