#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <dirent.h>
#include <sys/types.h>
#include <iostream>
#include <QString>
#include <QPaintEvent>
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QIcon>
#include <QSize>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <QFont>
#include <QPalette>

using namespace std;
Ui::MainWindow *ui_p;
extern STR str;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pthread_t geci_display;
    pthread_create(&geci_display, NULL, my_geci, ui);
    pthread_detach(geci_display);

    ui_p = ui;

    ui->setupUi(this);

    QFont ft;
    ft.setPointSize(20);
    ui->label_3->setFont(ft);
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->label_3->setPalette(pa);

    ui->listWidget->setStyleSheet("background-color:transparent");
    QPixmap pixmap;
    pixmap.load(":/image/song_pause.png");
    pixmap.scaled(ui->pushButton_pause->size(), Qt::KeepAspectRatio);
    QIcon icon;
    icon.addPixmap(pixmap);
    ui->pushButton_pause->setIcon(icon);
    ui->pushButton_pause->setIconSize(QSize(50, 50));

    QPixmap pixmap1;
    pixmap1.load(":/image/song_voice.png");
    pixmap1.scaled(ui->pushButton_mute->size(), Qt::KeepAspectRatio);
    QIcon icon1;
    icon1.addPixmap(pixmap1);
    ui->pushButton_mute->setIcon(icon1);
    ui->pushButton_mute->setIconSize(QSize(30, 30));

    while(str.gequ[str.i] != NULL)
    {
        ui->listWidget->addItem(str.gequ[str.i]);
        str.i++;
    }

    ui->volume->setValue(50);
    str.volume_current1 = 50;
    str.volume_current = 50;
   // ui->label_volume->setText((const QString &)num);

    connect(ui->time, &QSlider::sliderReleased, [=](){
        str.seek = !str.seek;
        int value_b = ui->time->value();
        float time_a = value_b/100;
        float current_time = str.time_full * time_a;

        if(current_time > str.time_current)
        {
            str.seek_value = (int)(current_time-str.time_current);
        }
        else
        {
            str.seek_value = (int)(-(current_time-str.time_current));
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
//背景
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    QPixmap pix;

    pix.load(":/image/4.jpg");
    pix = pix.scaled(this->width(), this->height());

    painter->drawPixmap(0, 0, pix.width(), pix.height(), pix);

}

//歌名列表切换
void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    str.flag++;
    str.qiege = !str.qiege;
    str.currentrow = ui->listWidget->currentRow();
    strcpy(str.current_gequ, str.gequ[str.currentrow]);   
    ui->label_1->setText((const QString &)str.current_gequ);
    this->update();
}

//上一曲
void MainWindow::on_pushButton_pre_clicked()
{
    str.pre = !str.pre;
    str.flag++;
    this->update();

    if(str.flag_style % 3 == 0)
    {
        if((str.currentrow - 1) >= 0)
        {
            str.currentrow--;
            strcpy(str.current_gequ, str.gequ[str.currentrow]);
        }
        else
        {
            str.currentrow = str.i - 1;
            strcpy(str.current_gequ, str.gequ[str.currentrow]);
        }
    }
    else if(str.flag_style % 3 == 1)
    {
        strcpy(str.current_gequ, str.gequ[str.currentrow]);
    }
    else if(str.flag_style % 3 == 2)
    {
        str.currentrow = rand()%str.i;
        strcpy(str.current_gequ, str.gequ[str.currentrow]);
    }
    ui->label_1->setText((const QString &)str.current_gequ);
}

//下一曲
void MainWindow::on_pushButton_next_clicked()
{
    str.next = !str.next;
    str.flag++;
    this->update();

    if(str.flag_style % 3 == 0)
    {
        if(str.gequ[str.currentrow+1] != NULL)
        {
            str.currentrow++;
            strcpy(str.current_gequ, str.gequ[str.currentrow]);
        }
        else
        {
            str.currentrow = 0;
            strcpy(str.current_gequ, str.gequ[str.currentrow]);
        }
    }
    else if(str.flag_style % 3 == 1)
    {
        strcpy(str.current_gequ, str.gequ[str.currentrow]);
    }
    else if(str.flag_style % 3 == 2)
    {
        str.currentrow = rand()%str.i;
        strcpy(str.current_gequ, str.gequ[str.currentrow]);
    }
    ui->label_1->setText((const QString &)str.current_gequ);

}

//后退10秒
void MainWindow::on_pushButton_back_clicked()
{
    str.flag_b ++;
    str.back = !str.back;
}

//前进10秒
void MainWindow::on_pushButton_front_clicked()
{
    str.front = !str.front;
}

//暂停
void MainWindow::on_pushButton_pause_clicked()
{
    str.pause = !str.pause;
    if(str.pause == false)
    {
        QPixmap pixmap;
        pixmap.load(":/image/song_pause.png");
        pixmap.scaled(ui->pushButton_pause->size(), Qt::KeepAspectRatio);
        QIcon icon;
        icon.addPixmap(pixmap);
        ui_p->pushButton_pause->setIcon(icon);
        ui->pushButton_pause->setIconSize(QSize(50, 50));
    }
    else
    {
        QPixmap pixmap;
        pixmap.load(":/image/song_play.png");
        pixmap.scaled(ui->pushButton_pause->size(), Qt::KeepAspectRatio);
        QIcon icon;
        icon.addPixmap(pixmap);
        ui->pushButton_pause->setIcon(icon);
        ui->pushButton_pause->setIconSize(QSize(50, 50));
    }
}

//静音
void MainWindow::on_pushButton_mute_clicked()
{
    str.mute = !str.mute;
    if(str.mute == false)
    {
        QPixmap pixmap1;
        pixmap1.load(":/image/song_voice.png");
        pixmap1.scaled(ui->pushButton_mute->size(), Qt::KeepAspectRatio);
        QIcon icon1;
        icon1.addPixmap(pixmap1);
        ui->pushButton_mute->setIcon(icon1);
        ui->pushButton_mute->setIconSize(QSize(30, 30));
        char buf[8] = "";
        sprintf(buf, "%02d%", str.volume_current1);
        //ui->label_volume->setText((const QString &)buf);
        ui->volume->setValue(str.volume_current1);
    }
    else
    {
        QPixmap pixmap1;
        pixmap1.load(":/image/song_mute.png");
        pixmap1.scaled(ui->pushButton_mute->size(), Qt::KeepAspectRatio);
        QIcon icon1;
        icon1.addPixmap(pixmap1);
        ui->pushButton_mute->setIcon(icon1);
        ui->pushButton_mute->setIconSize(QSize(30, 30));
        char buf[8] = "";
        sprintf(buf, "%02d%", 0);
        //ui->label_volume->setText((const QString &)buf);
        str.volume_current1 = str.volume_current;
        ui->volume->setValue(0);
    }
}

void *deal_fun(void *arg)
{
    int fd = *(int *)arg;
    while(1)
    {
        char buf[128] = "";
        read(fd, buf, sizeof(buf));

        char cmd[128] = "";
        sscanf(buf, "%[^=]", cmd);

        if(strcmp(cmd, "ANS_PERCENT_POSITION") == 0)
        {
            sscanf(buf, "%*[^=]=%d", &str.percent_pos);
            ui_p->time->setValue(str.percent_pos);
        }
        else if(strcmp(cmd, "ANS_TIME_POSITION") == 0)
        {
            sscanf(buf, "%*[^=]=%f", &str.time_current);
            char time[16] = "";
            sprintf(time, "%02d:%02d", (int)(str.time_current+0.5)/60, (int)(str.time_current+0.5)%60);
            ui_p->label_currenttime->setText((const QString &)time);
        }
        else if(strcmp(cmd, "ANS_LENGTH") == 0)
        {
            sscanf(buf, "%*[^=]=%f", &str.time_full);
            char time[16] = "";
            sprintf(time, "%02d:%02d", (int)(str.time_full+0.5)/60, (int)(str.time_full+0.5)%60);
            ui_p->label_fulltime->setText((const QString &)time);
        }

        if((int)str.time_current > (int)(str.time_full - 2) && str.time_full != 0)
        {
            if(str.flag_style % 3 == 0)
            {
                str.qiege = !str.qiege;
                str.flag++;

                if(str.gequ[str.currentrow+1] != NULL)
                {
                    str.currentrow++;
                    strcpy(str.current_gequ, str.gequ[str.currentrow]);
                }
                else
                {
                    str.currentrow = 0;
                    strcpy(str.current_gequ, str.gequ[str.currentrow]);
                }
            }
            else if(str.flag_style % 3 == 1)
            {
                str.qiege = !str.qiege;
                str.flag++;

                strcpy(str.current_gequ, str.gequ[str.currentrow]);
            }
            else if(str.flag_style % 3 == 2)
            {
                str.qiege = !str.qiege;
                str.flag++;

                str.currentrow = rand()%str.i;
                strcpy(str.current_gequ, str.gequ[str.currentrow]);
            }

            ui_p->label_1->setText((const QString &)str.current_gequ);
        }
    }
}

void *deal_fun2(void *arg)
{
    bool qiege_tmp = false ;
    bool pre_tmp = false;
    bool next_tmp = false;
    bool mute_tmp = false;
    bool volume_tmp = false;
    bool seek_tmp = false;
    bool back_tmp = false;
    bool front_tmp = false;

    int fifo_fd = *(int *)arg ;

    write(fifo_fd, "volume 50 1\n", strlen("volume 50 1\n"));

    while(1)
    {
        if(str.pause == true)
        {
            write(fifo_fd, "pause\n", strlen("pause\n"));
            while(1)
            {
                if(str.pause == false)
                {
                    write(fifo_fd, "pause\n", strlen("pause\n"));
                    break;
                }
                fflush(stdout);
            }
        }
        else
        {
            if(str.qiege != qiege_tmp)
            {
                char buf[64] = "";
                qiege_tmp = str.qiege;
                sprintf(buf, "loadfile /home/edu/work/mplayer/mplayer/%s\n", str.current_gequ);
                write(fifo_fd, buf, strlen(buf));
            }
            if(str.pre != pre_tmp)
            {
                pre_tmp = str.pre;
                char buf[64] = "";
                sprintf(buf, "loadfile /home/edu/work/mplayer/mplayer/%s\n", str.current_gequ);
                write(fifo_fd, buf, strlen(buf));
            }
            if(str.next != next_tmp)
            {
                next_tmp = str.next;
                char buf[64] = "";
                sprintf(buf, "loadfile /home/edu/work/mplayer/mplayer/%s\n", str.current_gequ);
                write(fifo_fd, buf, strlen(buf));
            }
            if(str.mute != mute_tmp)
            {
                if(str.mute == true)
                {
                    write(fifo_fd, "mute 1\n", strlen("mute 1\n"));
                }
                else
                {
                    write(fifo_fd, "mute 0\n", strlen("mute 0\n"));
                }
                mute_tmp = str.mute;
            }

            if(str.back != back_tmp)
            {
                write(fifo_fd, "seek -10\n", strlen("seek -10\n"));

                back_tmp = str.back;
            }
            if(str.front != front_tmp)
            {
                write(fifo_fd, "seek 10\n", strlen("seek 10\n"));
                front_tmp = str.front;
            }
            if(str.seek != seek_tmp)
            {
                char seek_a[32] = "";
                sprintf(seek_a, "seek %d\n", str.seek_value);
                write(fifo_fd, seek_a, strlen(seek_a));

                seek_tmp = str.seek;
            }

            usleep(100*1000);
            write(fifo_fd, "get_percent_pos\n", strlen("get_percent_pos\n"));
            usleep(100*1000);
            write(fifo_fd,"get_time_pos\n", strlen("get_time_pos\n"));
            usleep(100*1000);
            write(fifo_fd,"get_time_length\n", strlen("get_time_length\n"));
        }
    }

}

//获取歌名
void get_song(char **gequ1)
{

    DIR *dir = opendir("/home/edu/work/mplayer");

    int i = 0;
    while(1)
    {
        struct dirent *ent = readdir(dir);

        if(ent == NULL)
        {
            break;
        }

        if(ent->d_type == DT_REG)
        {
            gequ1[i] = ent->d_name;
            i++;
        }
    }
}

void *my_geci(void *arg)
{
    Ui::MainWindow *ui_tmp = (Ui::MainWindow *)arg;
    strcpy(str.current_gequ, str.gequ[str.currentrow]);
    int flag = 0;
    int flag_tmp = 0;
    int flag_b_tmp = 0;

    get_lrc();
    my_qiege();
    set_lrc();

    vector<int>::const_iterator ret_v = str.v.begin();
    vector<int>::const_iterator ret_v_tmp1 = str.v.begin();
    vector<int>::const_iterator ret_v_tmp2 = str.v.begin();
    vector<int>::const_iterator ret_v_tmp3 = str.v.begin();

    while(1)
    {

        if(str.flag_b != flag_b_tmp)
        {
            flag_b_tmp = str.flag_b;
            sleep(1);
            while(*(ret_v) > (int)str.time_current)
            {
                ret_v --;
                ret_v_tmp3 = ret_v;
            }
            ret_v_tmp2 = --ret_v;
        }

        if(*ret_v == 0)
        {
            ret_v++;
        }
        ret_v_tmp1 = ret_v_tmp3;

        usleep(100*1000);
        string geci = str.geci1[*ret_v_tmp1];
        char *geci1 = NULL;
        geci1 = (char *)(geci.c_str());
        //printf("888888888 geci1 = %s\n", geci1);
        ui_tmp->label_3->setText((const QString &)geci1);

        ret_v_tmp1++;
        geci = str.geci1[*ret_v_tmp1];
        geci1 = (char *)(geci.c_str());
        ui_tmp->label_4->setText((const QString &)geci1);

        ret_v_tmp1++;
        geci = str.geci1[*ret_v_tmp1];
        geci1 = (char *)(geci.c_str());
        ui_tmp->label_5->setText((const QString &)geci1);

        if((*ret_v) == (int)str.time_current || (*ret_v) < (int)str.time_current)
        {
            flag++;
            ret_v_tmp2 = ret_v_tmp3;
            ret_v_tmp3 = ret_v;
            ret_v++;
        }
        if(flag >1)
        {
            string geci = str.geci1[*ret_v_tmp2];
            char *geci1 = NULL;
            geci1 = (char *)(geci.c_str());
            ui_tmp->label_2->setText((const QString &)geci1);
        }
        if((flag_tmp != str.flag) && (str.flag > 1))
        {
            flag = 0;
            char *a = " ";
            ui_p->label_2->setText((const QString &)a);
            str.v.clear();
            str.geci1.clear();
            flag_tmp = str.flag;
            get_lrc();
            my_qiege();
            set_lrc();
            ret_v = str.v.begin();
            ret_v_tmp3 = str.v.begin();
            ret_v_tmp2 = str.v.begin();

            sleep(1);
        }
    }
}

//根据歌名获取同名的歌词文件
void get_lrc(void)
{

    char gequ_tmp1[128] = "";
    char gequ_tmp2[64] = "";
    sscanf(str.current_gequ, "%[^.].mp3", gequ_tmp2);
    sprintf(gequ_tmp1, "%s.lrc", gequ_tmp2);
    FILE *fp = fopen(gequ_tmp1, "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    fseek(fp, 0, 2);

    str.len = ftell(fp);

    rewind(fp);

    str.lrc = (LRC *)calloc(1, str.len);

    fread(str.lrc, str.len, 1, fp);

    fclose(fp);

    return;
}

//切换歌曲
void my_qiege(void)
{
    int i = 0;

    str.geci[i] = strtok((char *)str.lrc, "\r\n");
    while ((str.geci[i]) != NULL)
    {
        i++;
        str.geci[i] = strtok(NULL, "\r\n");
    }

    str.row = i ;

    return;
}

void set_lrc(void)
{
    LRC tmp;
    int i = 0;

    for (i = 4; i < str.row; i++)
    {
        char *p_lrc = str.geci[i];

        while ((*p_lrc) == '[')
        {
            p_lrc += 10;
        }

        char *p_t = str.geci[i];
        while ((*p_t) == '[')
        {
            int m = 0;
            int s = 0;

            strcpy(tmp.lrc, p_lrc);
            sscanf(p_t, "[%d:%d", &m, &s);

            tmp.time = m * 60 + s;

            str.geci1.insert(make_pair(tmp.time, tmp.lrc));
            str.v.push_back(tmp.time);

            p_t += 10;
        }
    }

    sort(str.v.begin(), str.v.end(), less<int>());

    return;
}

//音量滑动条
void MainWindow::on_volume_sliderMoved(int position)
{
    mkfifo("fifo_cmd",0666);
    int fd = open("fifo_cmd",O_WRONLY);
    char volume[128] = "";
    sprintf(volume, "volume %d 1\n", position);
    write(fd, volume, strlen(volume));
}
