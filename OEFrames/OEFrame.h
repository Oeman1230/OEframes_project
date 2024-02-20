
#ifndef __OEFRAME_H__
#define __OEFRAME_H__

#include <memory>

#include "BaseWindowObj.h"
#include <OETexture.h>

class OEFrame : public BaseWindowObj
{

public:

	OEFrame(SDL_Renderer* FrameRenderer);
	virtual ~OEFrame();


	void setBackground(Color color);
	void setForeground(Color color) {};
	//void setVisible(bool newState);

public:

	void setBounds(int x, int y, int width, int height);
	void setLocation(int x, int y);
	//void setBorder(Color color, int thickness);

	SDL_Rect getSizes();

public:

	void repaintAll();
	void repaint();
	void update() {};

public:

	std::weak_ptr<OETexture> getOETexture() { return frameTexture; }
	//void setText(std::string text);

protected:

	//void _createBorder();

protected:

	std::shared_ptr<OETexture> frameTexture;
	//std::shared_ptr<OETexture> borderTexture;

	//Color borderColor;
	//int borderThickness;

protected:

	SDL_Renderer* _winRenderer;

};




#endif // !__OEFRAME_H__


