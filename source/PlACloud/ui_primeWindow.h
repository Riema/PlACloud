/********************************************************************************
** Form generated from reading UI file 'primeWindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMEWINDOW_H
#define UI_PRIMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_primeWindow
{
public:
    QAction *actionOwnCloud;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QComboBox *selectionComboBox;
    QStackedWidget *ownCloudStackedWidget;
    QWidget *filePage;
    QGridLayout *gridLayout_2;
    QPushButton *dolphinButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textBrowser;
    QWidget *configPage;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *configCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout_3;
    QPushButton *restoreLastConfigButton;
    QPushButton *saveConfButton;
    QListView *configListView;
    QPushButton *restoreConfigButton;
    QWidget *contactPage;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *contactCheckBox;
    QPushButton *contactButton_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *calendarCheckBox;
    QPushButton *calendarButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *setPage;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *serverLabel;
    QLineEdit *serverLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *portLabel;
    QSpinBox *portSpinBox;
    QSpacerItem *horizontalSpacer_5;
    QScrollBar *horizontalScrollBar;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *fileButton;
    QPushButton *configButton;
    QPushButton *contactButton;
    QPushButton *settingsButton;
    QToolBar *toolBar;

    void setupUi(QMainWindow *primeWindow)
    {
        if (primeWindow->objectName().isEmpty())
            primeWindow->setObjectName(QString::fromUtf8("primeWindow"));
        primeWindow->resize(798, 488);
        primeWindow->setLayoutDirection(Qt::LeftToRight);
        actionOwnCloud = new QAction(primeWindow);
        actionOwnCloud->setObjectName(QString::fromUtf8("actionOwnCloud"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/ownCloud.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionOwnCloud->setIcon(icon);
        centralwidget = new QWidget(primeWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        selectionComboBox = new QComboBox(centralwidget);
        selectionComboBox->setObjectName(QString::fromUtf8("selectionComboBox"));

        verticalLayout->addWidget(selectionComboBox);

        ownCloudStackedWidget = new QStackedWidget(centralwidget);
        ownCloudStackedWidget->setObjectName(QString::fromUtf8("ownCloudStackedWidget"));
        filePage = new QWidget();
        filePage->setObjectName(QString::fromUtf8("filePage"));
        gridLayout_2 = new QGridLayout(filePage);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        dolphinButton = new QPushButton(filePage);
        dolphinButton->setObjectName(QString::fromUtf8("dolphinButton"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(dolphinButton->sizePolicy().hasHeightForWidth());
        dolphinButton->setSizePolicy(sizePolicy);
        dolphinButton->setMinimumSize(QSize(75, 75));

        gridLayout_2->addWidget(dolphinButton, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        textBrowser = new QTextBrowser(filePage);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 1, 1, 1, 1);

        ownCloudStackedWidget->addWidget(filePage);
        configPage = new QWidget();
        configPage->setObjectName(QString::fromUtf8("configPage"));
        verticalLayout_4 = new QVBoxLayout(configPage);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        configCheckBox = new QCheckBox(configPage);
        configCheckBox->setObjectName(QString::fromUtf8("configCheckBox"));
        configCheckBox->setMinimumSize(QSize(50, 50));

        verticalLayout_2->addWidget(configCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(configPage);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        spinBox = new QSpinBox(configPage);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimumSize(QSize(50, 50));
        spinBox->setMaximum(31);
        spinBox->setValue(5);

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        restoreLastConfigButton = new QPushButton(configPage);
        restoreLastConfigButton->setObjectName(QString::fromUtf8("restoreLastConfigButton"));
        restoreLastConfigButton->setMinimumSize(QSize(50, 50));

        verticalLayout_3->addWidget(restoreLastConfigButton);

        saveConfButton = new QPushButton(configPage);
        saveConfButton->setObjectName(QString::fromUtf8("saveConfButton"));
        saveConfButton->setMinimumSize(QSize(50, 50));

        verticalLayout_3->addWidget(saveConfButton);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        configListView = new QListView(configPage);
        configListView->setObjectName(QString::fromUtf8("configListView"));

        verticalLayout_4->addWidget(configListView);

        restoreConfigButton = new QPushButton(configPage);
        restoreConfigButton->setObjectName(QString::fromUtf8("restoreConfigButton"));
        restoreConfigButton->setMinimumSize(QSize(50, 50));

        verticalLayout_4->addWidget(restoreConfigButton);

        ownCloudStackedWidget->addWidget(configPage);
        contactPage = new QWidget();
        contactPage->setObjectName(QString::fromUtf8("contactPage"));
        horizontalLayout_9 = new QHBoxLayout(contactPage);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(242, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        contactCheckBox = new QCheckBox(contactPage);
        contactCheckBox->setObjectName(QString::fromUtf8("contactCheckBox"));
        contactCheckBox->setMinimumSize(QSize(50, 50));

        horizontalLayout_8->addWidget(contactCheckBox);

        contactButton_2 = new QPushButton(contactPage);
        contactButton_2->setObjectName(QString::fromUtf8("contactButton_2"));
        contactButton_2->setMinimumSize(QSize(75, 75));

        horizontalLayout_8->addWidget(contactButton_2);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        calendarCheckBox = new QCheckBox(contactPage);
        calendarCheckBox->setObjectName(QString::fromUtf8("calendarCheckBox"));
        calendarCheckBox->setMinimumSize(QSize(50, 50));
        calendarCheckBox->setIconSize(QSize(50, 50));

        horizontalLayout_4->addWidget(calendarCheckBox);

        calendarButton = new QPushButton(contactPage);
        calendarButton->setObjectName(QString::fromUtf8("calendarButton"));
        calendarButton->setMinimumSize(QSize(75, 75));

        horizontalLayout_4->addWidget(calendarButton);


        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_9->addLayout(verticalLayout_5);

        horizontalSpacer_3 = new QSpacerItem(242, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        ownCloudStackedWidget->addWidget(contactPage);
        setPage = new QWidget();
        setPage->setObjectName(QString::fromUtf8("setPage"));
        verticalLayout_8 = new QVBoxLayout(setPage);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        userNameLabel = new QLabel(setPage);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setMinimumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(userNameLabel);

        userNameLineEdit = new QLineEdit(setPage);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        userNameLineEdit->setMinimumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(userNameLineEdit);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        serverLabel = new QLabel(setPage);
        serverLabel->setObjectName(QString::fromUtf8("serverLabel"));
        serverLabel->setMinimumSize(QSize(50, 50));

        horizontalLayout_6->addWidget(serverLabel);

        serverLineEdit = new QLineEdit(setPage);
        serverLineEdit->setObjectName(QString::fromUtf8("serverLineEdit"));
        serverLineEdit->setMinimumSize(QSize(50, 50));
        serverLineEdit->setInputMethodHints(Qt::ImhUrlCharactersOnly);

        horizontalLayout_6->addWidget(serverLineEdit);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        portLabel = new QLabel(setPage);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));
        portLabel->setMinimumSize(QSize(50, 50));

        horizontalLayout_7->addWidget(portLabel);

        portSpinBox = new QSpinBox(setPage);
        portSpinBox->setObjectName(QString::fromUtf8("portSpinBox"));
        portSpinBox->setMinimumSize(QSize(50, 50));
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(80);

        horizontalLayout_7->addWidget(portSpinBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_8->addLayout(horizontalLayout_7);

        ownCloudStackedWidget->addWidget(setPage);
        userNameLineEdit->raise();
        serverLineEdit->raise();
        portSpinBox->raise();
        userNameLabel->raise();
        serverLabel->raise();
        portLabel->raise();

        verticalLayout->addWidget(ownCloudStackedWidget);

        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setMaximum(4);
        horizontalScrollBar->setPageStep(1);
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setAlignment(Qt::AlignCenter);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        fileButton = new QPushButton(groupBox);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fileButton->sizePolicy().hasHeightForWidth());
        fileButton->setSizePolicy(sizePolicy2);
        fileButton->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(fileButton);

        configButton = new QPushButton(groupBox);
        configButton->setObjectName(QString::fromUtf8("configButton"));
        sizePolicy2.setHeightForWidth(configButton->sizePolicy().hasHeightForWidth());
        configButton->setSizePolicy(sizePolicy2);
        configButton->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(configButton);

        contactButton = new QPushButton(groupBox);
        contactButton->setObjectName(QString::fromUtf8("contactButton"));
        sizePolicy2.setHeightForWidth(contactButton->sizePolicy().hasHeightForWidth());
        contactButton->setSizePolicy(sizePolicy2);
        contactButton->setMinimumSize(QSize(50, 50));
        contactButton->setFlat(false);

        horizontalLayout->addWidget(contactButton);

        settingsButton = new QPushButton(groupBox);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        sizePolicy2.setHeightForWidth(settingsButton->sizePolicy().hasHeightForWidth());
        settingsButton->setSizePolicy(sizePolicy2);
        settingsButton->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(settingsButton);


        verticalLayout->addWidget(groupBox);

        primeWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(primeWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(120, 27));
        primeWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionOwnCloud);

        retranslateUi(primeWindow);
        QObject::connect(ownCloudStackedWidget, SIGNAL(currentChanged(int)), horizontalScrollBar, SLOT(setValue(int)));
        QObject::connect(horizontalScrollBar, SIGNAL(valueChanged(int)), ownCloudStackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(configCheckBox, SIGNAL(clicked(bool)), spinBox, SLOT(setEnabled(bool)));

        ownCloudStackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(primeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *primeWindow)
    {
        primeWindow->setWindowTitle(QApplication::translate("primeWindow", "PlACloud", 0, QApplication::UnicodeUTF8));
        actionOwnCloud->setText(QApplication::translate("primeWindow", "own&Cloud", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOwnCloud->setToolTip(QApplication::translate("primeWindow", "New ownCloud configuration", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        dolphinButton->setText(QApplication::translate("primeWindow", "Open Dolphin", 0, QApplication::UnicodeUTF8));
        configCheckBox->setText(QApplication::translate("primeWindow", "Backup kConfig automatically", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("primeWindow", "Backup kConfig every (day):", 0, QApplication::UnicodeUTF8));
        restoreLastConfigButton->setText(QApplication::translate("primeWindow", "Restore last configuration", 0, QApplication::UnicodeUTF8));
        saveConfButton->setText(QApplication::translate("primeWindow", "Backup configuration now", 0, QApplication::UnicodeUTF8));
        restoreConfigButton->setText(QApplication::translate("primeWindow", "Restore selected configuration", 0, QApplication::UnicodeUTF8));
        contactCheckBox->setText(QApplication::translate("primeWindow", "Synchronize contacts", 0, QApplication::UnicodeUTF8));
        contactButton_2->setText(QApplication::translate("primeWindow", "Open Kontact Touch", 0, QApplication::UnicodeUTF8));
        calendarCheckBox->setText(QApplication::translate("primeWindow", "Synchronize calendar", 0, QApplication::UnicodeUTF8));
        calendarButton->setText(QApplication::translate("primeWindow", "Open KOrganizer", 0, QApplication::UnicodeUTF8));
        userNameLabel->setText(QApplication::translate("primeWindow", "User name:", 0, QApplication::UnicodeUTF8));
        serverLabel->setText(QApplication::translate("primeWindow", "URL of cloud server:", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("primeWindow", "Port: ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("primeWindow", "Menu", 0, QApplication::UnicodeUTF8));
        fileButton->setText(QApplication::translate("primeWindow", "Files", 0, QApplication::UnicodeUTF8));
        configButton->setText(QApplication::translate("primeWindow", "Configuration", 0, QApplication::UnicodeUTF8));
        contactButton->setText(QApplication::translate("primeWindow", "Contacts/Calendar", 0, QApplication::UnicodeUTF8));
        settingsButton->setText(QApplication::translate("primeWindow", "Settings", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("primeWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class primeWindow: public Ui_primeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMEWINDOW_H
