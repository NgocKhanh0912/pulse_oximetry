# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'dev.ui'
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
    QLineEdit, QPushButton, QSizePolicy, QWidget)

class Ui_Dev_UI(object):
    def setupUi(self, Dev_UI):
        if not Dev_UI.objectName():
            Dev_UI.setObjectName(u"Dev_UI")
        Dev_UI.resize(1535, 814)
        self.Set_filter_coeffs = QGroupBox(Dev_UI)
        self.Set_filter_coeffs.setObjectName(u"Set_filter_coeffs")
        self.Set_filter_coeffs.setGeometry(QRect(30, 390, 631, 231))
        self.lbl_numerator = QLabel(self.Set_filter_coeffs)
        self.lbl_numerator.setObjectName(u"lbl_numerator")
        self.lbl_numerator.setGeometry(QRect(20, 90, 81, 20))
        self.lbl_denominator = QLabel(self.Set_filter_coeffs)
        self.lbl_denominator.setObjectName(u"lbl_denominator")
        self.lbl_denominator.setGeometry(QRect(20, 140, 101, 20))
        self.line_nume_order_4 = QLineEdit(self.Set_filter_coeffs)
        self.line_nume_order_4.setObjectName(u"line_nume_order_4")
        self.line_nume_order_4.setGeometry(QRect(140, 90, 81, 26))
        self.line_nume_order_3 = QLineEdit(self.Set_filter_coeffs)
        self.line_nume_order_3.setObjectName(u"line_nume_order_3")
        self.line_nume_order_3.setGeometry(QRect(240, 90, 81, 26))
        self.line_nume_order_2 = QLineEdit(self.Set_filter_coeffs)
        self.line_nume_order_2.setObjectName(u"line_nume_order_2")
        self.line_nume_order_2.setGeometry(QRect(340, 90, 81, 26))
        self.line_nume_order_1 = QLineEdit(self.Set_filter_coeffs)
        self.line_nume_order_1.setObjectName(u"line_nume_order_1")
        self.line_nume_order_1.setGeometry(QRect(440, 90, 81, 26))
        self.lbl_order_4 = QLabel(self.Set_filter_coeffs)
        self.lbl_order_4.setObjectName(u"lbl_order_4")
        self.lbl_order_4.setGeometry(QRect(160, 40, 63, 20))
        self.lbl_order_3 = QLabel(self.Set_filter_coeffs)
        self.lbl_order_3.setObjectName(u"lbl_order_3")
        self.lbl_order_3.setGeometry(QRect(260, 40, 63, 20))
        self.lbl_order_2 = QLabel(self.Set_filter_coeffs)
        self.lbl_order_2.setObjectName(u"lbl_order_2")
        self.lbl_order_2.setGeometry(QRect(360, 40, 63, 20))
        self.lbl_order_1 = QLabel(self.Set_filter_coeffs)
        self.lbl_order_1.setObjectName(u"lbl_order_1")
        self.lbl_order_1.setGeometry(QRect(460, 40, 63, 20))
        self.lbl_coefficients = QLabel(self.Set_filter_coeffs)
        self.lbl_coefficients.setObjectName(u"lbl_coefficients")
        self.lbl_coefficients.setGeometry(QRect(20, 40, 81, 20))
        self.line_nume_order_0 = QLineEdit(self.Set_filter_coeffs)
        self.line_nume_order_0.setObjectName(u"line_nume_order_0")
        self.line_nume_order_0.setGeometry(QRect(540, 90, 81, 26))
        self.lbl_order_0 = QLabel(self.Set_filter_coeffs)
        self.lbl_order_0.setObjectName(u"lbl_order_0")
        self.lbl_order_0.setGeometry(QRect(560, 40, 63, 20))
        self.line_deno_order_2 = QLineEdit(self.Set_filter_coeffs)
        self.line_deno_order_2.setObjectName(u"line_deno_order_2")
        self.line_deno_order_2.setGeometry(QRect(340, 140, 81, 26))
        self.line_deno_order_3 = QLineEdit(self.Set_filter_coeffs)
        self.line_deno_order_3.setObjectName(u"line_deno_order_3")
        self.line_deno_order_3.setGeometry(QRect(240, 140, 81, 26))
        self.line_deno_order_0 = QLineEdit(self.Set_filter_coeffs)
        self.line_deno_order_0.setObjectName(u"line_deno_order_0")
        self.line_deno_order_0.setGeometry(QRect(540, 140, 81, 26))
        self.line_deno_order_1 = QLineEdit(self.Set_filter_coeffs)
        self.line_deno_order_1.setObjectName(u"line_deno_order_1")
        self.line_deno_order_1.setGeometry(QRect(440, 140, 81, 26))
        self.line_deno_order_4 = QLineEdit(self.Set_filter_coeffs)
        self.line_deno_order_4.setObjectName(u"line_deno_order_4")
        self.line_deno_order_4.setGeometry(QRect(140, 140, 81, 26))
        self.btn_set_filter_coeffs = QPushButton(self.Set_filter_coeffs)
        self.btn_set_filter_coeffs.setObjectName(u"btn_set_filter_coeffs")
        self.btn_set_filter_coeffs.setGeometry(QRect(250, 190, 131, 29))
        self.Filtered_PPG = QGroupBox(Dev_UI)
        self.Filtered_PPG.setObjectName(u"Filtered_PPG")
        self.Filtered_PPG.setGeometry(QRect(680, 390, 821, 331))
        self.btn_switch_to_user_ui = QPushButton(Dev_UI)
        self.btn_switch_to_user_ui.setObjectName(u"btn_switch_to_user_ui")
        self.btn_switch_to_user_ui.setGeometry(QRect(720, 740, 141, 41))
        self.Raw_PPG = QGroupBox(Dev_UI)
        self.Raw_PPG.setObjectName(u"Raw_PPG")
        self.Raw_PPG.setGeometry(QRect(680, 20, 821, 351))
        self.Set_RTC = QGroupBox(Dev_UI)
        self.Set_RTC.setObjectName(u"Set_RTC")
        self.Set_RTC.setGeometry(QRect(30, 20, 631, 351))
        self.cbb_set_day = QComboBox(self.Set_RTC)
        self.cbb_set_day.addItem("")
        self.cbb_set_day.addItem("")
        self.cbb_set_day.addItem("")
        self.cbb_set_day.addItem("")
        self.cbb_set_day.addItem("")
        self.cbb_set_day.addItem("")
        self.cbb_set_day.addItem("")
        self.cbb_set_day.setObjectName(u"cbb_set_day")
        self.cbb_set_day.setGeometry(QRect(230, 80, 91, 26))
        self.btn_set_rtc = QPushButton(self.Set_RTC)
        self.btn_set_rtc.setObjectName(u"btn_set_rtc")
        self.btn_set_rtc.setGeometry(QRect(270, 310, 93, 29))
        self.cbb_mode_time = QComboBox(self.Set_RTC)
        self.cbb_mode_time.addItem("")
        self.cbb_mode_time.addItem("")
        self.cbb_mode_time.setObjectName(u"cbb_mode_time")
        self.cbb_mode_time.setGeometry(QRect(170, 30, 111, 26))
        self.lbl_epoch_time = QLabel(self.Set_RTC)
        self.lbl_epoch_time.setObjectName(u"lbl_epoch_time")
        self.lbl_epoch_time.setGeometry(QRect(20, 270, 141, 21))
        self.lbl_mode_time = QLabel(self.Set_RTC)
        self.lbl_mode_time.setObjectName(u"lbl_mode_time")
        self.lbl_mode_time.setGeometry(QRect(20, 30, 81, 20))
        self.line_epoch_time = QLineEdit(self.Set_RTC)
        self.line_epoch_time.setObjectName(u"line_epoch_time")
        self.line_epoch_time.setGeometry(QRect(170, 270, 251, 26))
        self.lbl_date_time = QLabel(self.Set_RTC)
        self.lbl_date_time.setObjectName(u"lbl_date_time")
        self.lbl_date_time.setGeometry(QRect(20, 80, 131, 20))
        self.lbl_day = QLabel(self.Set_RTC)
        self.lbl_day.setObjectName(u"lbl_day")
        self.lbl_day.setGeometry(QRect(170, 80, 51, 20))
        self.cbb_set_date = QComboBox(self.Set_RTC)
        self.cbb_set_date.setObjectName(u"cbb_set_date")
        self.cbb_set_date.setGeometry(QRect(410, 80, 91, 26))
        self.lbl_date = QLabel(self.Set_RTC)
        self.lbl_date.setObjectName(u"lbl_date")
        self.lbl_date.setGeometry(QRect(360, 80, 51, 20))
        self.cbb_set_month = QComboBox(self.Set_RTC)
        self.cbb_set_month.setObjectName(u"cbb_set_month")
        self.cbb_set_month.setGeometry(QRect(230, 130, 91, 26))
        self.lbl_month = QLabel(self.Set_RTC)
        self.lbl_month.setObjectName(u"lbl_month")
        self.lbl_month.setGeometry(QRect(170, 130, 51, 20))
        self.cbb_set_year = QComboBox(self.Set_RTC)
        self.cbb_set_year.setObjectName(u"cbb_set_year")
        self.cbb_set_year.setGeometry(QRect(410, 130, 91, 26))
        self.lbl_year = QLabel(self.Set_RTC)
        self.lbl_year.setObjectName(u"lbl_year")
        self.lbl_year.setGeometry(QRect(360, 130, 41, 20))
        self.cbb_set_hour = QComboBox(self.Set_RTC)
        self.cbb_set_hour.setObjectName(u"cbb_set_hour")
        self.cbb_set_hour.setGeometry(QRect(230, 180, 91, 26))
        self.lbl_hour = QLabel(self.Set_RTC)
        self.lbl_hour.setObjectName(u"lbl_hour")
        self.lbl_hour.setGeometry(QRect(170, 180, 51, 20))
        self.cbb_set_min = QComboBox(self.Set_RTC)
        self.cbb_set_min.setObjectName(u"cbb_set_min")
        self.cbb_set_min.setGeometry(QRect(410, 180, 91, 26))
        self.lbl_min = QLabel(self.Set_RTC)
        self.lbl_min.setObjectName(u"lbl_min")
        self.lbl_min.setGeometry(QRect(360, 180, 51, 20))
        self.lbl_sec = QLabel(self.Set_RTC)
        self.lbl_sec.setObjectName(u"lbl_sec")
        self.lbl_sec.setGeometry(QRect(270, 220, 51, 20))
        self.cbb_set_sec = QComboBox(self.Set_RTC)
        self.cbb_set_sec.setObjectName(u"cbb_set_sec")
        self.cbb_set_sec.setGeometry(QRect(320, 220, 91, 26))
        self.Notification = QGroupBox(Dev_UI)
        self.Notification.setObjectName(u"Notification")
        self.Notification.setGeometry(QRect(30, 630, 631, 91))
        self.lbl_notification = QLabel(self.Notification)
        self.lbl_notification.setObjectName(u"lbl_notification")
        self.lbl_notification.setGeometry(QRect(28, 40, 81, 20))
        self.line_notification = QLineEdit(self.Notification)
        self.line_notification.setObjectName(u"line_notification")
        self.line_notification.setGeometry(QRect(110, 40, 491, 26))

        self.retranslateUi(Dev_UI)

        QMetaObject.connectSlotsByName(Dev_UI)
    # setupUi

    def retranslateUi(self, Dev_UI):
        Dev_UI.setWindowTitle(QCoreApplication.translate("Dev_UI", u"Form", None))
        self.Set_filter_coeffs.setTitle(QCoreApplication.translate("Dev_UI", u"Set Filter Coefficients in s-domain (4-order Butterworth Filter)", None))
        self.lbl_numerator.setText(QCoreApplication.translate("Dev_UI", u"Numerator:", None))
        self.lbl_denominator.setText(QCoreApplication.translate("Dev_UI", u"Denominator:", None))
        self.lbl_order_4.setText(QCoreApplication.translate("Dev_UI", u"order 4", None))
        self.lbl_order_3.setText(QCoreApplication.translate("Dev_UI", u"order 3", None))
        self.lbl_order_2.setText(QCoreApplication.translate("Dev_UI", u"order 2", None))
        self.lbl_order_1.setText(QCoreApplication.translate("Dev_UI", u"order 1", None))
        self.lbl_coefficients.setText(QCoreApplication.translate("Dev_UI", u"Coefficients:", None))
        self.lbl_order_0.setText(QCoreApplication.translate("Dev_UI", u"order 0", None))
        self.btn_set_filter_coeffs.setText(QCoreApplication.translate("Dev_UI", u"Set coefficients", None))
        self.Filtered_PPG.setTitle(QCoreApplication.translate("Dev_UI", u"Filtered PPG signal", None))
        self.btn_switch_to_user_ui.setText(QCoreApplication.translate("Dev_UI", u"Switch to User UI", None))
        self.Raw_PPG.setTitle(QCoreApplication.translate("Dev_UI", u"Raw PPG signal", None))
        self.Set_RTC.setTitle(QCoreApplication.translate("Dev_UI", u"Set RTC", None))
        self.cbb_set_day.setItemText(0, QCoreApplication.translate("Dev_UI", u"Monday", None))
        self.cbb_set_day.setItemText(1, QCoreApplication.translate("Dev_UI", u"Tuesday", None))
        self.cbb_set_day.setItemText(2, QCoreApplication.translate("Dev_UI", u"Wednesday", None))
        self.cbb_set_day.setItemText(3, QCoreApplication.translate("Dev_UI", u"Thursday", None))
        self.cbb_set_day.setItemText(4, QCoreApplication.translate("Dev_UI", u"Friday", None))
        self.cbb_set_day.setItemText(5, QCoreApplication.translate("Dev_UI", u"Saturday", None))
        self.cbb_set_day.setItemText(6, QCoreApplication.translate("Dev_UI", u"Sunday", None))

        self.btn_set_rtc.setText(QCoreApplication.translate("Dev_UI", u"Set time", None))
        self.cbb_mode_time.setItemText(0, QCoreApplication.translate("Dev_UI", u"Date time", None))
        self.cbb_mode_time.setItemText(1, QCoreApplication.translate("Dev_UI", u"Epoch time", None))

        self.lbl_epoch_time.setText(QCoreApplication.translate("Dev_UI", u"Epoch time (GMT0):", None))
        self.lbl_mode_time.setText(QCoreApplication.translate("Dev_UI", u"Mode time:", None))
        self.lbl_date_time.setText(QCoreApplication.translate("Dev_UI", u"Date time (GMT7):", None))
        self.lbl_day.setText(QCoreApplication.translate("Dev_UI", u"Day:", None))
        self.lbl_date.setText(QCoreApplication.translate("Dev_UI", u"Date:", None))
        self.lbl_month.setText(QCoreApplication.translate("Dev_UI", u"Month:", None))
        self.lbl_year.setText(QCoreApplication.translate("Dev_UI", u"Year:", None))
        self.lbl_hour.setText(QCoreApplication.translate("Dev_UI", u"Hour:", None))
        self.lbl_min.setText(QCoreApplication.translate("Dev_UI", u"Min:", None))
        self.lbl_sec.setText(QCoreApplication.translate("Dev_UI", u"Sec:", None))
        self.Notification.setTitle(QCoreApplication.translate("Dev_UI", u"Notification", None))
        self.lbl_notification.setText(QCoreApplication.translate("Dev_UI", u"Status:", None))
    # retranslateUi

