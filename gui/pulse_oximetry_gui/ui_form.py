# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'form.ui'
##
## Created by: Qt User Interface Compiler version 6.7.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QComboBox, QGroupBox, QLabel,
    QLineEdit, QMainWindow, QMenuBar, QPushButton,
    QSizePolicy, QStatusBar, QTextEdit, QWidget)

class Ui_User_UI(object):
    def setupUi(self, User_UI):
        if not User_UI.objectName():
            User_UI.setObjectName(u"User_UI")
        User_UI.resize(1534, 845)
        self.centralwidget = QWidget(User_UI)
        self.centralwidget.setObjectName(u"centralwidget")
        self.Heart_rate_graph = QGroupBox(self.centralwidget)
        self.Heart_rate_graph.setObjectName(u"Heart_rate_graph")
        self.Heart_rate_graph.setGeometry(QRect(500, 20, 1001, 451))
        self.btn_switch_to_dev_ui = QPushButton(self.centralwidget)
        self.btn_switch_to_dev_ui.setObjectName(u"btn_switch_to_dev_ui")
        self.btn_switch_to_dev_ui.setGeometry(QRect(690, 730, 141, 41))
        self.Notification = QGroupBox(self.centralwidget)
        self.Notification.setObjectName(u"Notification")
        self.Notification.setGeometry(QRect(30, 610, 451, 111))
        self.lbl_thre_noti = QLabel(self.Notification)
        self.lbl_thre_noti.setObjectName(u"lbl_thre_noti")
        self.lbl_thre_noti.setGeometry(QRect(20, 50, 121, 20))
        self.line_thre_noti = QLineEdit(self.Notification)
        self.line_thre_noti.setObjectName(u"line_thre_noti")
        self.line_thre_noti.setGeometry(QRect(150, 50, 281, 26))
        self.Connectivity = QGroupBox(self.centralwidget)
        self.Connectivity.setObjectName(u"Connectivity")
        self.Connectivity.setGeometry(QRect(30, 20, 451, 181))
        self.lbl_com = QLabel(self.Connectivity)
        self.lbl_com.setObjectName(u"lbl_com")
        self.lbl_com.setGeometry(QRect(60, 30, 81, 20))
        self.lbl_baudrate = QLabel(self.Connectivity)
        self.lbl_baudrate.setObjectName(u"lbl_baudrate")
        self.lbl_baudrate.setGeometry(QRect(60, 80, 71, 20))
        self.btn_connect_com = QPushButton(self.Connectivity)
        self.btn_connect_com.setObjectName(u"btn_connect_com")
        self.btn_connect_com.setGeometry(QRect(110, 130, 93, 29))
        self.cbb_com = QComboBox(self.Connectivity)
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.addItem("")
        self.cbb_com.setObjectName(u"cbb_com")
        self.cbb_com.setGeometry(QRect(220, 30, 111, 26))
        self.cbb_baudrate = QComboBox(self.Connectivity)
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.addItem("")
        self.cbb_baudrate.setObjectName(u"cbb_baudrate")
        self.cbb_baudrate.setGeometry(QRect(220, 80, 111, 26))
        self.btn_check_com = QPushButton(self.Connectivity)
        self.btn_check_com.setObjectName(u"btn_check_com")
        self.btn_check_com.setGeometry(QRect(250, 130, 93, 29))
        self.Threshold = QGroupBox(self.centralwidget)
        self.Threshold.setObjectName(u"Threshold")
        self.Threshold.setGeometry(QRect(30, 210, 451, 221))
        self.lbl_low_level = QLabel(self.Threshold)
        self.lbl_low_level.setObjectName(u"lbl_low_level")
        self.lbl_low_level.setGeometry(QRect(30, 50, 151, 20))
        self.lbl_high_level = QLabel(self.Threshold)
        self.lbl_high_level.setObjectName(u"lbl_high_level")
        self.lbl_high_level.setGeometry(QRect(30, 120, 161, 20))
        self.line_low_level = QLineEdit(self.Threshold)
        self.line_low_level.setObjectName(u"line_low_level")
        self.line_low_level.setGeometry(QRect(220, 40, 113, 41))
        self.line_high_level = QLineEdit(self.Threshold)
        self.line_high_level.setObjectName(u"line_high_level")
        self.line_high_level.setGeometry(QRect(220, 110, 113, 41))
        self.btn_set_threshold = QPushButton(self.Threshold)
        self.btn_set_threshold.setObjectName(u"btn_set_threshold")
        self.btn_set_threshold.setGeometry(QRect(170, 170, 111, 29))
        self.lbl_bpm_1 = QLabel(self.Threshold)
        self.lbl_bpm_1.setObjectName(u"lbl_bpm_1")
        self.lbl_bpm_1.setGeometry(QRect(350, 50, 71, 20))
        self.lbl_bpm_2 = QLabel(self.Threshold)
        self.lbl_bpm_2.setObjectName(u"lbl_bpm_2")
        self.lbl_bpm_2.setGeometry(QRect(350, 120, 71, 20))
        self.Record = QGroupBox(self.centralwidget)
        self.Record.setObjectName(u"Record")
        self.Record.setGeometry(QRect(500, 480, 1001, 241))
        self.txt_record = QTextEdit(self.Record)
        self.txt_record.setObjectName(u"txt_record")
        self.txt_record.setGeometry(QRect(20, 30, 831, 201))
        self.btn_read_record = QPushButton(self.Record)
        self.btn_read_record.setObjectName(u"btn_read_record")
        self.btn_read_record.setGeometry(QRect(870, 60, 111, 29))
        self.btn_clear_record = QPushButton(self.Record)
        self.btn_clear_record.setObjectName(u"btn_clear_record")
        self.btn_clear_record.setGeometry(QRect(870, 120, 111, 29))
        self.btn_clear_graph = QPushButton(self.Record)
        self.btn_clear_graph.setObjectName(u"btn_clear_graph")
        self.btn_clear_graph.setGeometry(QRect(870, 180, 111, 29))
        self.Interval = QGroupBox(self.centralwidget)
        self.Interval.setObjectName(u"Interval")
        self.Interval.setGeometry(QRect(30, 440, 451, 161))
        self.lbl_interval = QLabel(self.Interval)
        self.lbl_interval.setObjectName(u"lbl_interval")
        self.lbl_interval.setGeometry(QRect(70, 50, 81, 20))
        self.line_set_interval = QLineEdit(self.Interval)
        self.line_set_interval.setObjectName(u"line_set_interval")
        self.line_set_interval.setGeometry(QRect(220, 40, 113, 41))
        self.lbl_s = QLabel(self.Interval)
        self.lbl_s.setObjectName(u"lbl_s")
        self.lbl_s.setGeometry(QRect(350, 50, 31, 20))
        self.btn_set_interval = QPushButton(self.Interval)
        self.btn_set_interval.setObjectName(u"btn_set_interval")
        self.btn_set_interval.setGeometry(QRect(170, 110, 111, 29))
        User_UI.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(User_UI)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 1534, 26))
        User_UI.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(User_UI)
        self.statusbar.setObjectName(u"statusbar")
        User_UI.setStatusBar(self.statusbar)

        self.retranslateUi(User_UI)

        QMetaObject.connectSlotsByName(User_UI)
    # setupUi

    def retranslateUi(self, User_UI):
        User_UI.setWindowTitle(QCoreApplication.translate("User_UI", u"MainWindow", None))
        self.Heart_rate_graph.setTitle(QCoreApplication.translate("User_UI", u"Heart rate", None))
        self.btn_switch_to_dev_ui.setText(QCoreApplication.translate("User_UI", u"Switch to Dev UI", None))
        self.Notification.setTitle(QCoreApplication.translate("User_UI", u"Threshold Notification", None))
        self.lbl_thre_noti.setText(QCoreApplication.translate("User_UI", u"Threshold status:", None))
        self.Connectivity.setTitle(QCoreApplication.translate("User_UI", u"Connectivity", None))
        self.lbl_com.setText(QCoreApplication.translate("User_UI", u"COM Port:", None))
        self.lbl_baudrate.setText(QCoreApplication.translate("User_UI", u"Baudrate:", None))
        self.btn_connect_com.setText(QCoreApplication.translate("User_UI", u"Connect", None))
        self.cbb_com.setItemText(0, QCoreApplication.translate("User_UI", u"COM0", None))
        self.cbb_com.setItemText(1, QCoreApplication.translate("User_UI", u"COM1", None))
        self.cbb_com.setItemText(2, QCoreApplication.translate("User_UI", u"COM2", None))
        self.cbb_com.setItemText(3, QCoreApplication.translate("User_UI", u"COM3", None))
        self.cbb_com.setItemText(4, QCoreApplication.translate("User_UI", u"COM4", None))
        self.cbb_com.setItemText(5, QCoreApplication.translate("User_UI", u"COM5", None))
        self.cbb_com.setItemText(6, QCoreApplication.translate("User_UI", u"COM6", None))
        self.cbb_com.setItemText(7, QCoreApplication.translate("User_UI", u"COM7", None))
        self.cbb_com.setItemText(8, QCoreApplication.translate("User_UI", u"COM8", None))
        self.cbb_com.setItemText(9, QCoreApplication.translate("User_UI", u"COM9", None))
        self.cbb_com.setItemText(10, QCoreApplication.translate("User_UI", u"COM10", None))
        self.cbb_com.setItemText(11, QCoreApplication.translate("User_UI", u"COM11", None))
        self.cbb_com.setItemText(12, QCoreApplication.translate("User_UI", u"COM12", None))
        self.cbb_com.setItemText(13, QCoreApplication.translate("User_UI", u"COM13", None))
        self.cbb_com.setItemText(14, QCoreApplication.translate("User_UI", u"COM14", None))
        self.cbb_com.setItemText(15, QCoreApplication.translate("User_UI", u"COM15", None))
        self.cbb_com.setItemText(16, QCoreApplication.translate("User_UI", u"COM16", None))
        self.cbb_com.setItemText(17, QCoreApplication.translate("User_UI", u"COM17", None))
        self.cbb_com.setItemText(18, QCoreApplication.translate("User_UI", u"COM18", None))
        self.cbb_com.setItemText(19, QCoreApplication.translate("User_UI", u"COM19", None))
        self.cbb_com.setItemText(20, QCoreApplication.translate("User_UI", u"COM20", None))

        self.cbb_baudrate.setItemText(0, QCoreApplication.translate("User_UI", u"1200", None))
        self.cbb_baudrate.setItemText(1, QCoreApplication.translate("User_UI", u"2400", None))
        self.cbb_baudrate.setItemText(2, QCoreApplication.translate("User_UI", u"4800", None))
        self.cbb_baudrate.setItemText(3, QCoreApplication.translate("User_UI", u"9600", None))
        self.cbb_baudrate.setItemText(4, QCoreApplication.translate("User_UI", u"14400", None))
        self.cbb_baudrate.setItemText(5, QCoreApplication.translate("User_UI", u"19200", None))
        self.cbb_baudrate.setItemText(6, QCoreApplication.translate("User_UI", u"38400", None))
        self.cbb_baudrate.setItemText(7, QCoreApplication.translate("User_UI", u"57600", None))
        self.cbb_baudrate.setItemText(8, QCoreApplication.translate("User_UI", u"115200", None))
        self.cbb_baudrate.setItemText(9, QCoreApplication.translate("User_UI", u"230400", None))
        self.cbb_baudrate.setItemText(10, QCoreApplication.translate("User_UI", u"460800", None))
        self.cbb_baudrate.setItemText(11, QCoreApplication.translate("User_UI", u"921600", None))
        self.cbb_baudrate.setItemText(12, QCoreApplication.translate("User_UI", u"1000000", None))

        self.btn_check_com.setText(QCoreApplication.translate("User_UI", u"Check COM", None))
        self.Threshold.setTitle(QCoreApplication.translate("User_UI", u"Set Threshold", None))
        self.lbl_low_level.setText(QCoreApplication.translate("User_UI", u"Heart rate low level:", None))
        self.lbl_high_level.setText(QCoreApplication.translate("User_UI", u"Heart rate high level:", None))
        self.btn_set_threshold.setText(QCoreApplication.translate("User_UI", u"Set threshold", None))
        self.lbl_bpm_1.setText(QCoreApplication.translate("User_UI", u"BPM", None))
        self.lbl_bpm_2.setText(QCoreApplication.translate("User_UI", u"BPM", None))
        self.Record.setTitle(QCoreApplication.translate("User_UI", u"Heart rate record", None))
        self.btn_read_record.setText(QCoreApplication.translate("User_UI", u"Read record", None))
        self.btn_clear_record.setText(QCoreApplication.translate("User_UI", u"Clear record", None))
        self.btn_clear_graph.setText(QCoreApplication.translate("User_UI", u"Clear graph", None))
        self.Interval.setTitle(QCoreApplication.translate("User_UI", u"Set Interval", None))
        self.lbl_interval.setText(QCoreApplication.translate("User_UI", u"Interval:", None))
        self.lbl_s.setText(QCoreApplication.translate("User_UI", u"s", None))
        self.btn_set_interval.setText(QCoreApplication.translate("User_UI", u"Set interval", None))
    # retranslateUi

