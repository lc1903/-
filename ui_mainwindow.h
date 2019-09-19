/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_1;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_5;
    QSlider *time;
    QSlider *volume;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_pre;
    QPushButton *pushButton_next;
    QPushButton *pushButton_back;
    QPushButton *pushButton_front;
    QPushButton *pushButton_mute;
    QLabel *label_currenttime;
    QLabel *label_fulltime;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 600);
        MainWindow->setMinimumSize(QSize(1024, 600));
        MainWindow->setMaximumSize(QSize(1024, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(80, 60, 211, 431));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(520, 60, 401, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_1 = new QLabel(verticalLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_1->setPalette(palette);
        QFont font;
        font.setPointSize(14);
        label_1->setFont(font);

        verticalLayout->addWidget(label_1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        time = new QSlider(centralWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(470, 400, 311, 21));
        time->setOrientation(Qt::Horizontal);
        volume = new QSlider(centralWidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setGeometry(QRect(710, 480, 111, 31));
        volume->setOrientation(Qt::Horizontal);
        pushButton_pause = new QPushButton(centralWidget);
        pushButton_pause->setObjectName(QStringLiteral("pushButton_pause"));
        pushButton_pause->setGeometry(QRect(480, 480, 41, 31));
        pushButton_pause->setFlat(true);
        pushButton_pre = new QPushButton(centralWidget);
        pushButton_pre->setObjectName(QStringLiteral("pushButton_pre"));
        pushButton_pre->setGeometry(QRect(430, 480, 31, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/song_pre.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_pre->setIcon(icon);
        pushButton_pre->setIconSize(QSize(25, 25));
        pushButton_pre->setCheckable(false);
        pushButton_pre->setFlat(true);
        pushButton_next = new QPushButton(centralWidget);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));
        pushButton_next->setGeometry(QRect(540, 480, 31, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/song_next.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_next->setIcon(icon1);
        pushButton_next->setIconSize(QSize(25, 25));
        pushButton_next->setFlat(true);
        pushButton_back = new QPushButton(centralWidget);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(380, 480, 31, 31));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/song_back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon2);
        pushButton_back->setIconSize(QSize(25, 25));
        pushButton_back->setFlat(true);
        pushButton_front = new QPushButton(centralWidget);
        pushButton_front->setObjectName(QStringLiteral("pushButton_front"));
        pushButton_front->setGeometry(QRect(590, 480, 31, 31));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/song_front.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_front->setIcon(icon3);
        pushButton_front->setIconSize(QSize(25, 25));
        pushButton_front->setFlat(true);
        pushButton_mute = new QPushButton(centralWidget);
        pushButton_mute->setObjectName(QStringLiteral("pushButton_mute"));
        pushButton_mute->setGeometry(QRect(670, 480, 31, 31));
        pushButton_mute->setFlat(true);
        label_currenttime = new QLabel(centralWidget);
        label_currenttime->setObjectName(QStringLiteral("label_currenttime"));
        label_currenttime->setGeometry(QRect(420, 390, 71, 31));
        label_fulltime = new QLabel(centralWidget);
        label_fulltime->setObjectName(QStringLiteral("label_fulltime"));
        label_fulltime->setGeometry(QRect(790, 390, 81, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_1->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton_pause->setText(QString());
        pushButton_pre->setText(QString());
        pushButton_next->setText(QString());
        pushButton_back->setText(QString());
        pushButton_front->setText(QString());
        pushButton_mute->setText(QString());
        label_currenttime->setText(QString());
        label_fulltime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
