/********************************************************************************
** Form generated from reading UI file 'advice.ui'
**
** Created: Wed Aug 3 19:47:29 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVICE_H
#define UI_ADVICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Advice
{
public:
    QDialogButtonBox *buttonBox;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Advice)
    {
        if (Advice->objectName().isEmpty())
            Advice->setObjectName(QString::fromUtf8("Advice"));
        Advice->resize(735, 389);
        buttonBox = new QDialogButtonBox(Advice);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(380, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textBrowser = new QTextBrowser(Advice);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 10, 701, 321));

        retranslateUi(Advice);
        QObject::connect(buttonBox, SIGNAL(accepted()), Advice, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Advice, SLOT(reject()));

        QMetaObject::connectSlotsByName(Advice);
    } // setupUi

    void retranslateUi(QDialog *Advice)
    {
        Advice->setWindowTitle(QApplication::translate("Advice", "Dialog", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("Advice", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\241\214\346\230\237\350\277\236\347\217\240\347\256\200\344\273\213\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \346\234\254\347\263\273\347\273\237\346\217\220\344\276\233\344\272\206\346\211\200\346\234\211\347\232\204\345\244\252\351\230\263\347\263\273\345\205\253\351\242\227\350\241\214\346\230\237\350\277\236\347\217\240\347"
                        "\232\204\346\243\200\346\265\213\345\212\237\350\203\275\343\200\202\344\275\234\344\270\272\344\270\200\347\247\215\345\260\221\350\247\201\347\232\204\347\216\260\350\261\241\357\274\214\344\275\240\345\217\257\350\203\275\345\220\214\346\227\266\345\270\214\346\234\233\347\234\213\345\210\260\346\233\264\345\260\221\347\232\204\342\200\234\344\270\203\346\230\237\350\277\236\347\217\240\342\200\235\357\274\214\347\224\232\350\207\263\346\230\257\342\200\234\345\205\255\346\230\237\350\277\236\347\217\240\342\200\235\343\200\201\342\200\234\344\272\224\346\230\237\350\277\236\347\217\240\342\200\235\343\200\202\345\233\240\346\255\244\357\274\214\346\202\250\345\217\257\350\203\275\350\277\230\351\234\200\350\246\201\346\210\221\344\273\254\346\233\264\345\277\253\351\200\237\347\232\204\346\225\260\346\215\256\346\217\220\344\276\233\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<"
                        "p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \345\246\202\346\236\234\346\202\250\345\270\214\346\234\233\347\234\213\345\210\260\350\276\203\345\270\270\350\247\201\347\232\204\342\200\234\344\272\224\346\230\237\350\277\236\347\217\240\342\200\235\347\224\232\350\207\263\346\230\257\342\200\234\345\233\233\346\230\237\350\277\236\347\217\240\342\200\235\357\274\214\351\202\243\344\271\210\357\274\2142000\345\271\2645\346\234\210\344\273\275\345\260\206\346\230\257\351\235\236\345\270\270\345\245\275\347\232\204\351\200\211\346\213\251\357\274\214\346\233\264\345\244\232\347\232\204\350\241\214\346\230\237\350\277\236\347\217\240\357\274\214\344\276\213\345\246\202\342\200\234\345\205\255\346\230\237\350\277\236\347\217\240\342\200\235\345\222\214\342\200\234\344\270\203\346\230\237\350\277\236\347\217\240\342\200\235\345\217\221\347\224\237\347\232\204\345\211\215\345\220\216\357\274\214\344\271\237\351\203\275\344\274\232\346\234"
                        "\211\350\277\231\344\272\233\347\216\260\350\261\241\344\272\247\347\224\237\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	\345\257\271\344\272\216\350\276\203\345\244\232\347\232\204\350\241\214\346\230\237\350\277\236\347\217\240\357\274\214\346\210\221\344\273\254\346\216\250\350\215\220\344\273\245\344\270\213\346\227\266\351\227\264\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2003\345\271\26408\346\234\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2009\345\271\26403\346\234\210\345\222\2142010\345\271\26403\346\234\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2059\345\271\26403\346\234\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom"
                        ":0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2060\345\271\26404\346\234\210\345\210\2602060\345\271\26405\346\234\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2079\345\271\26407\346\234\210\345\222\2142080\345\271\26407\346\234\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2098\345\271\26408\346\234\210\345\222\2142099\345\271\26408\346\234\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2148\345\271\26412\346\234\210\357\274\210\346\234\200\344\270\272\346\216\245\350\277\221\342\200\234\345\205\253\346\230\237\350\277\236\347\217\240\342\200\235\357\274\211</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2168\345\271\26402\346\234"
                        "\210\345\222\2142169\345\271\26402\346\234\210\344\273\245\345\217\2122170\345\271\26402\346\234\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2188\345\271\26403\346\234\210\345\222\2142189\345\271\26404\346\234\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2258\345\271\26408\346\234\210\345\222\2142259\345\271\26407\346\234\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		2277\345\271\26410\346\234\210		</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	\344\275\240\345\217\257\344\273\245\345\234\250\344\273\245\344\270\212\346\227\266\351\227"
                        "\264\347\232\204\345\206\205\346\211\276\345\210\260\347\233\270\345\205\263\347\232\204\347\216\260\350\261\241\343\200\202</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Advice: public Ui_Advice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVICE_H
