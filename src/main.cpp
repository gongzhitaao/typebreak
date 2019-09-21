#include <QApplication>
#include <QCommandLineParser>
#include <QWindow>
#include <iostream>
#include <vector>

#include "widget.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QCoreApplication::setApplicationName("block-qt");
  QCoreApplication::setApplicationVersion("1.1");

  QCommandLineParser parser;

  QCommandLineOption durationOption(
      QStringList() << "d" << "duration",
      QCoreApplication::translate("main", "Shadows the screen for <x> minutes"),
      QCoreApplication::translate("main", "x"));
  parser.addOption(durationOption);

  parser.setApplicationDescription(
      "\nShadows the screen for a while so that you could take a"
      "break.\nThis program does NOT invoke itself, I used it along "
      "with `cron` program.");
  parser.addHelpOption();
  parser.addVersionOption();

  parser.process(app);

  int duration = parser.value(durationOption).toInt();
  if (!duration) duration = 5;

  auto all_screens = app.screens();
  std::vector<Widget *> widgets;
  for (int i = 0; i < all_screens.size(); ++i) {
    Widget *w = new Widget(duration);
    w->show();
    w->windowHandle()->setScreen(all_screens[i]);
    widgets.push_back(w);
  }

  int retcode = app.exec();
  for (Widget *w : widgets) delete w;
  return retcode;
}
