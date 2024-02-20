#include "OEFrame.h"
#include <OET_Figures/OET_Square.h>

OEFrame::OEFrame(SDL_Renderer* winRenderer)
{
	if (winRenderer == nullptr)
	{
		throw BaseWinObjErr("NO_RENDERER");
	}

	_winRenderer = winRenderer;

	frameTexture = std::make_shared<OETexture>(winRenderer);
	//borderTexture = std::make_shared<OETexture>(winRenderer);
	//borderThickness = 0;

}


OEFrame::~OEFrame()
{

	

	_winRenderer = nullptr;

	frameTexture->free();
	frameTexture.reset();
	
	//borderTexture->free();
	//borderTexture.reset();

}

void OEFrame::setBounds(int x, int y, int width, int height)
{
	frameTexture->setOnScreenPos(x, y);
	frameTexture->setWidth(width);
	frameTexture->setHeight(height);
}

void OEFrame::setLocation(int x, int y)
{
	frameTexture->setOnScreenPos(x, y);

}

//void OEFrame::_createBorder()
//{
//
//	int width = frameTexture->getWidth();
//	int height = frameTexture->getHeight();
//
//	if (width <= 0 || height <= 0)
//	{
//		return;
//	}
//
//	TSquare tempSquare = TSquare(_winRenderer);
//
//	borderTexture->free();
//
//	borderTexture = tempSquare.createSquare(width, height, borderColor);
//
//
//}
//

//
//void OEFrame::setBorder(Color color, int thickness)
//{
//	
//
//	TSquare tempSquare = TSquare(_winRenderer);
//
//	
//
//}

void OEFrame::setBackground(Color color)
{

	if (frameTexture->getWidth() <= 0 || frameTexture->getHeight() <= 0)
	{
		throw BaseWinObjErr("NO_SIZE");
	}

	TSquare tempBack = TSquare(_winRenderer);

	SDL_Rect onScreenRect = frameTexture->getOnScreenRect();

	frameTexture->free();

	auto tempTexture = tempBack.createSquare
	(
		onScreenRect.w, onScreenRect.h, color
	);


	tempTexture->setOnScreenPos(onScreenRect.x, onScreenRect.y);

	frameTexture.swap(tempTexture);
	tempTexture.reset();

}

void OEFrame::repaint()
{

	SDL_Texture* thisTexture = frameTexture->getSDL_Texture();

	if (thisTexture == nullptr)
	{
		throw BaseWinObjErr("NO_TEXTURE");
	}

	if (isVisible == false)
	{
		return;
	}

	SDL_Rect onScreenTextureRect = frameTexture->getOnScreenRect();

	SDL_RenderCopy(_winRenderer, thisTexture, 0, &onScreenTextureRect);

}

void OEFrame::repaintAll()
{
	this->repaint();

	for (auto& inner_it : _innerWinObjects)
	{
		std::shared_ptr<OEFrame> frame = std::dynamic_pointer_cast<OEFrame>(inner_it);

		if (frame == nullptr)
		{
			try
			{
				inner_it->repaint();
			}
			catch (const FunctionNotRealised&)
			{

			}
			continue;
		}

		frame->repaintAll();

	}

}

SDL_Rect OEFrame::getSizes()
{
	if (frameTexture == nullptr)
	{
		throw BaseWinObjErr("NO_TEXTURE");
	}

	return frameTexture->getOnScreenRect();

}
