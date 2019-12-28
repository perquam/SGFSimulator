/********************************************************************************
** Form generated from reading UI file 'Verlet.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERLET_H
#define UI_VERLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "GLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_VerletClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *restart;
    QPushButton *clear;
    QDoubleSpinBox *wavelength_spinbox;
    QLabel *label_3;
    QLabel *distance_labelbox;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *e_spinbox;
    QLabel *label_2;
    QSpinBox *nob_spinbox;
    QLabel *label;
    QTextBrowser *textBrowser;
    QDoubleSpinBox *l_spinbox;
    QCheckBox *show_parameters;
    GLWidget *widget;

    void setupUi(QMainWindow *VerletClass)
    {
        if (VerletClass->objectName().isEmpty())
            VerletClass->setObjectName(QStringLiteral("VerletClass"));
        VerletClass->resize(992, 722);
        VerletClass->setMinimumSize(QSize(0, 722));
        VerletClass->setMaximumSize(QSize(992, 722));
        VerletClass->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        VerletClass->setAnimated(true);
        centralWidget = new QWidget(VerletClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 11, 5, -1);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, -1, 0, -1);
        restart = new QPushButton(centralWidget);
        restart->setObjectName(QStringLiteral("restart"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(restart->sizePolicy().hasHeightForWidth());
        restart->setSizePolicy(sizePolicy);
        restart->setMinimumSize(QSize(20, 0));
        restart->setMaximumSize(QSize(300, 300));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        restart->setFont(font);
        restart->setAcceptDrops(false);
        restart->setAutoFillBackground(false);
        restart->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));

        gridLayout->addWidget(restart, 21, 0, 1, 2);

        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        sizePolicy.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy);
        clear->setMaximumSize(QSize(300, 300));
        clear->setBaseSize(QSize(0, 0));
        clear->setFont(font);
        clear->setAcceptDrops(false);
        clear->setLayoutDirection(Qt::LeftToRight);
        clear->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));
        clear->setAutoRepeatDelay(299);
        clear->setAutoDefault(false);
        clear->setFlat(false);

        gridLayout->addWidget(clear, 18, 0, 1, 2);

        wavelength_spinbox = new QDoubleSpinBox(centralWidget);
        wavelength_spinbox->setObjectName(QStringLiteral("wavelength_spinbox"));
        wavelength_spinbox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wavelength_spinbox->sizePolicy().hasHeightForWidth());
        wavelength_spinbox->setSizePolicy(sizePolicy1);
        wavelength_spinbox->setMinimumSize(QSize(20, 50));
        wavelength_spinbox->setMaximumSize(QSize(150, 50));
        wavelength_spinbox->setFont(font);
        wavelength_spinbox->setMouseTracking(false);
        wavelength_spinbox->setAcceptDrops(false);
        wavelength_spinbox->setLayoutDirection(Qt::LeftToRight);
        wavelength_spinbox->setAutoFillBackground(false);
        wavelength_spinbox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));
        wavelength_spinbox->setDecimals(0);
        wavelength_spinbox->setMinimum(380);
        wavelength_spinbox->setMaximum(750);
        wavelength_spinbox->setValue(600);

        gridLayout->addWidget(wavelength_spinbox, 4, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setMaximumSize(QSize(147, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Verdana"));
        font1.setPointSize(7);
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));

        gridLayout->addWidget(label_3, 4, 1, 1, 1);

        distance_labelbox = new QLabel(centralWidget);
        distance_labelbox->setObjectName(QStringLiteral("distance_labelbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(distance_labelbox->sizePolicy().hasHeightForWidth());
        distance_labelbox->setSizePolicy(sizePolicy2);
        distance_labelbox->setMaximumSize(QSize(150, 50));
        distance_labelbox->setFont(font);
        distance_labelbox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));

        gridLayout->addWidget(distance_labelbox, 8, 0, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(146, 50));
        label_5->setFont(font1);
        label_5->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));

        gridLayout->addWidget(label_5, 8, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(147, 50));
        label_6->setFont(font1);
        label_6->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));

        gridLayout->addWidget(label_6, 7, 1, 1, 1);

        e_spinbox = new QDoubleSpinBox(centralWidget);
        e_spinbox->setObjectName(QStringLiteral("e_spinbox"));
        sizePolicy.setHeightForWidth(e_spinbox->sizePolicy().hasHeightForWidth());
        e_spinbox->setSizePolicy(sizePolicy);
        e_spinbox->setMinimumSize(QSize(150, 50));
        e_spinbox->setMaximumSize(QSize(150, 50));
        e_spinbox->setFont(font);
        e_spinbox->setAcceptDrops(false);
        e_spinbox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));
        e_spinbox->setDecimals(5);
        e_spinbox->setMinimum(0);
        e_spinbox->setMaximum(1000);
        e_spinbox->setSingleStep(0.001);
        e_spinbox->setValue(1);

        gridLayout->addWidget(e_spinbox, 5, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(147, 50));
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));

        gridLayout->addWidget(label_2, 5, 1, 1, 1);

        nob_spinbox = new QSpinBox(centralWidget);
        nob_spinbox->setObjectName(QStringLiteral("nob_spinbox"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(nob_spinbox->sizePolicy().hasHeightForWidth());
        nob_spinbox->setSizePolicy(sizePolicy3);
        nob_spinbox->setMinimumSize(QSize(150, 50));
        nob_spinbox->setMaximumSize(QSize(150, 50));
        nob_spinbox->setFont(font);
        nob_spinbox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));
        nob_spinbox->setMinimum(1);
        nob_spinbox->setMaximum(100);

        gridLayout->addWidget(nob_spinbox, 7, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(147, 50));
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));

        gridLayout->addWidget(label, 6, 1, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(20, 0));
        textBrowser->setMaximumSize(QSize(300, 150));
        QFont font2;
        font2.setFamily(QStringLiteral("Verdana"));
        font2.setPointSize(9);
        textBrowser->setFont(font2);
        textBrowser->setAcceptDrops(false);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(0);
        textBrowser->setLineWrapMode(QTextEdit::WidgetWidth);
        textBrowser->setReadOnly(true);
        textBrowser->setAcceptRichText(true);

        gridLayout->addWidget(textBrowser, 1, 0, 1, 2);

        l_spinbox = new QDoubleSpinBox(centralWidget);
        l_spinbox->setObjectName(QStringLiteral("l_spinbox"));
        sizePolicy.setHeightForWidth(l_spinbox->sizePolicy().hasHeightForWidth());
        l_spinbox->setSizePolicy(sizePolicy);
        l_spinbox->setMinimumSize(QSize(20, 50));
        l_spinbox->setMaximumSize(QSize(150, 50));
        l_spinbox->setFont(font);
        l_spinbox->setAcceptDrops(false);
        l_spinbox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));
        l_spinbox->setReadOnly(false);
        l_spinbox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        l_spinbox->setDecimals(5);
        l_spinbox->setMinimum(0);
        l_spinbox->setMaximum(1000);
        l_spinbox->setSingleStep(0.001);
        l_spinbox->setValue(20.5);

        gridLayout->addWidget(l_spinbox, 6, 0, 1, 1);

        show_parameters = new QCheckBox(centralWidget);
        show_parameters->setObjectName(QStringLiteral("show_parameters"));
        show_parameters->setEnabled(true);
        sizePolicy.setHeightForWidth(show_parameters->sizePolicy().hasHeightForWidth());
        show_parameters->setSizePolicy(sizePolicy);
        show_parameters->setMaximumSize(QSize(300, 50));
        QFont font3;
        font3.setFamily(QStringLiteral("Verdana"));
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        font3.setKerning(false);
        show_parameters->setFont(font3);
        show_parameters->setLayoutDirection(Qt::LeftToRight);
        show_parameters->setAutoFillBackground(false);
        show_parameters->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 25);"));
        show_parameters->setChecked(false);
        show_parameters->setTristate(false);

        gridLayout->addWidget(show_parameters, 17, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);

        widget = new GLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(700, 700));
        widget->setMaximumSize(QSize(700, 700));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(widget);

        VerletClass->setCentralWidget(centralWidget);

        retranslateUi(VerletClass);
        QObject::connect(restart, SIGNAL(released()), VerletClass, SLOT(close()));

        clear->setDefault(false);


        QMetaObject::connectSlotsByName(VerletClass);
    } // setupUi

    void retranslateUi(QMainWindow *VerletClass)
    {
        VerletClass->setWindowTitle(QApplication::translate("VerletClass", "SGFSimulator", nullptr));
        restart->setText(QApplication::translate("VerletClass", "&Quit", nullptr));
        clear->setText(QApplication::translate("VerletClass", "Restart", nullptr));
        label_3->setText(QApplication::translate("VerletClass", "<html><head/><body><p align=\"center\">wavelength</p></body></html>", nullptr));
        distance_labelbox->setText(QApplication::translate("VerletClass", "0", nullptr));
        label_5->setText(QApplication::translate("VerletClass", "<html><head/><body><p align=\"center\">distance to center</p></body></html>", nullptr));
        label_6->setText(QApplication::translate("VerletClass", "<html><head/><body><p align=\"center\">number of objects</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("VerletClass", "<html><head/><body><p align=\"center\">e</p></body></html>", nullptr));
        label->setText(QApplication::translate("VerletClass", "<html><head/><body><p align=\"center\">l</p></body></html>", nullptr));
        textBrowser->setHtml(QApplication::translate("VerletClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Simulator of motion of objects in Schwarzschild spacetime.</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Please use LMB to add massive particle</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text"
                        "-indent:0px;\">and RMB to add photon.</p></body></html>", nullptr));
        show_parameters->setText(QApplication::translate("VerletClass", "show parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VerletClass: public Ui_VerletClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERLET_H
