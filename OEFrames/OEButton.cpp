
#include "OEButton.h"

OEButton::OEButton(OEWindow* win) : OEFrame(win->getRend())
{
	_winPtr = win;

	_pressedButtonTexture = frameTexture;
	_unpressedButtonTexture = frameTexture;

	win->addMouseClickListener([&](void* caller, void* arg)
		{
			OEButton* button = (OEButton*)caller;

			if (button->isClickable())
			{
				button->changeTextureToPressed();
			}
			
		}, this, ClickManager::Mode::ON_BTN_DOWN);

	win->addMouseClickListener([&](void* caller, void* arg)
		{
			OEButton* button = (OEButton*)caller;

			if (button->isClickable())
			{
				button->changeTextureToUnpressed();
				button->doClickActions(arg);
			}

		}, this, ClickManager::Mode::ON_CLICK);



}

OEButton::~OEButton()
{
	_winPtr = nullptr;

	_pressedButtonTexture.reset();
	_unpressedButtonTexture.reset();

}

void OEButton::changeTextureToPressed()
{
	frameTexture = _pressedButtonTexture;

}
void OEButton::changeTextureToUnpressed()
{
	frameTexture = _unpressedButtonTexture;

}

void OEButton::setPressedButtonTexture(std::shared_ptr<OEFrame> newTexture)
{
	_pressedButtonTexture.reset();
	_pressedButtonTexture = newTexture->getOETexture().lock();
}
void OEButton::setUnpressedButtonTexture(std::shared_ptr<OEFrame> newTexture)
{
	_unpressedButtonTexture.reset();
	_unpressedButtonTexture = newTexture->getOETexture().lock();
}


void OEButton::addClickListener(BaseWindowObj::BaseReaction action, void* caller)
{
	BaseWindowObj::BaseListener newListener;
	newListener.listener = caller;
	newListener.reaction = action;

	_onClickActions.push_back(newListener);

}


void OEButton::doClickActions(void* arg)
{

	for (auto& it : _onClickActions)
	{
		it.reaction(it.listener, arg);
	}


}

