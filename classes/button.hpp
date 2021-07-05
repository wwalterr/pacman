#ifndef BUTTON_H

#define BUTTON_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_font.h>

#include <allegro5/allegro_ttf.h>

class Button
{
private:
	ALLEGRO_BITMAP *icon;

	ALLEGRO_COLOR color;

	ALLEGRO_FONT *font;

	char *str;

	char *font_path;

	int font_size, font_flag;

	float font_x, font_y, icon_x, icon_y;

public:
	Button();

	Button(char *, char *, const int, const int, const int, const int, const int, const float, const float, char *, const float, const float);

	~Button(void);

	void updateFont(void);

	void setFontPath(char *);

	char *getFontPath(void);

	void setFontSize(const int);

	int getFontSize(void);

	void setFontFlag(const int);

	int getFontFlag(void);

	void setColor(const int, const int, const int);

	ALLEGRO_COLOR getColor(void);

	void setIconX(const float);

	float getIconX(void);

	void setIconY(const float);

	float getIconY(void);

	void setFontX(const float);

	float getFontX(void);

	void setFontY(const float);

	float getFontY(void);

	void setStr(char *);

	char *getStr(void);

	void setIcon(char *);

	ALLEGRO_BITMAP *getIcon(void);

	Button &showStr(void);

	void showIcon(void);
};

#endif