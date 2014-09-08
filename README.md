Typebreak
=========

Simple Qt5 frameless half transparent window shadows the screen for 10
minutes.  No mouse or keyboard blocking is implemented.  It's just a
window with a countdown timer.  It only tells you that you've got to
stop for 10 minutes, *if you would like to*.  Otherwise it could be
dismissed with <kbd>ALT</kbd> + <kbd>F4</kbd>.  It's all up to you.

*This program doesn't invoke itself*.  Instead, I use `cron` to run it
 every hour.

The crontab line command is

```bash
0 * * * * DISPLAY:0.0 /absolute/path/to/block-qt
```

Note the `DISPLAY:0.0`, reason for this could found in
[this thread](http://unix.stackexchange.com/questions/154451/qt-program-not-invoked-by-cron)

Currently there are no customization, not at all.  **JUST A WINDOW
WITH A COUNTDOWN TIMER**.
