For every graphical element this directory contain *.bmp and *.txt file.
*.bmp is used in SDL mode. *.txt - in terminal mode.
Format of *.txt file:
 First line: width;
 Second line: height;
 Every next 'height' lines: chars for the surface and metasymbols;
 Metasymbols is used for colore:
   ^S, ^s - special color.
   ^M - magenta foreground.
   ^m - magenta background.
   ^W - white foreground.
   ^w - white background.
   ^B - black foreground.
   ^b - black background.
   TODO more.

