#include "widget.h"
#include <QApplication>
#include <QCommandLineParser>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("block-qt");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;

    QCommandLineOption durationOption(
                QStringList() << "d" << "duration",
                QCoreApplication::translate("main", "Shadows the screen for <x> minutes"),
                QCoreApplication::translate("main", "x"));
    parser.addOption(durationOption);

    parser.setApplicationDescription("\nShadows the screen for a while so that you could take a break.\nThis program does NOT invoke itself, I used it along with `cron` program.");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.process(a);

    int duration = parser.value(durationOption).toInt();
    if (!duration) duration = 5;

    Widget w(duration);
    w.show();

    return a.exec();
}
