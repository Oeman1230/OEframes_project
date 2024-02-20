
#ifndef __CLICK_MANAGER_H__
#define __CLICK_MANAGER_H__

#include <vector>
#include <memory>
#include <functional>

#include "Box.h"

#include "../BaseWindowObj.h"
#include "../OEFrame.h"


class ClickManager
{
public:

	ClickManager(){}
	~ClickManager()
	{
		_waitingToMouseUpListener.listener = nullptr;

		_clickListeners.clear();
		_buttonDownListeners.clear();
		_buttonUpListeners.clear();
	}

	enum class Mode
	{
		ON_CLICK = 0,
		ON_BTN_DOWN,
		ON_BTN_UP
	};

public:

	/*void addMouseListener(BaseWindowObj::BaseReaction action, void* newListener)
	{
		if (newListener == nullptr)
		{
			throw BaseWindowObj::BaseWinObjErr("NO_LISTENER");
		}

		BaseWindowObj::BaseListener newElem;
		newElem.listener = newListener;
		newElem.reaction = action;

		_clickListeners.push_back(newElem);


	}*/

	void addMouseListener(BaseWindowObj::BaseReaction action, void* newListener, Mode mode = Mode::ON_CLICK)
	{
		if (newListener == nullptr)
		{
			throw BaseWindowObj::BaseWinObjErr("NO_LISTENER");
		}

		BaseWindowObj::BaseListener newElem;
		newElem.listener = newListener;
		newElem.reaction = action;

		switch (mode)
		{
		case Mode::ON_CLICK:
			{
			_clickListeners.push_back(newElem);
				break;
			}
		case Mode::ON_BTN_UP:
		{
			_buttonUpListeners.push_back(newElem);
			break;
		}
		case Mode::ON_BTN_DOWN:
		{
			_buttonDownListeners.push_back(newElem);
			break;
		}

		default:
			break;
		}


	}


	/*void handleClick(SDL_Event* curEvent)
	{

		if (curEvent->type == SDL_MOUSEBUTTONUP)
		{

			if (_waitingToMouseUpListener.listener == nullptr)
			{
				return;
			}

			auto listener = (BaseWindowObj*)(_waitingToMouseUpListener.listener);

			SDL_Rect itRect = listener->getSizes();

			Box<int> wrapBox = Box<int>(itRect.x, itRect.y, itRect.w, itRect.h);

			Box<int> mouseBox = Box<int>(curEvent->button.x, curEvent->button.y, 1, 1);

			if (wrapBox.contains(mouseBox))
			{
				_waitingToMouseUpListener.reaction(listener, curEvent);
			}


			return;
		}

		if (curEvent->type != SDL_MOUSEBUTTONDOWN)
		{
			return;
		}

		for (auto& it : _clickListeners)
		{
			if (it.listener == nullptr)
			{
				continue;
			}

			auto itListener = (BaseWindowObj*)(it.listener);

			SDL_Rect itRect = itListener->getSizes();

			Box<int> wrapBox = Box<int>(itRect.x, itRect.y, itRect.w, itRect.h);
			
			Box<int> mouseBox = Box<int>(curEvent->button.x, curEvent->button.y, 1, 1);

			if (wrapBox.contains(mouseBox))
			{
				_waitingToMouseUpListener = it;
			}



		}


	}*/

	void handleClick(SDL_Event* curEvent)
	{

		if (curEvent->type == SDL_MOUSEBUTTONUP)
		{
			_tryToFinishClick(curEvent);

			_handleButtonUp(curEvent);

			return;
		}

		if (curEvent->type == SDL_MOUSEBUTTONDOWN)
		{
			_handleButtonDown(curEvent);

		}

	}


private:

	void _tryToFinishClick(SDL_Event* curEvent)
	{
		if (_waitingToMouseUpListener.listener == nullptr)
		{
			return;
		}

		auto listener = (BaseWindowObj*)(_waitingToMouseUpListener.listener);

		SDL_Rect itRect = listener->getSizes();

		Box<int> wrapBox = Box<int>(itRect.x, itRect.y, itRect.w, itRect.h);

		Box<int> mouseBox = Box<int>(curEvent->button.x, curEvent->button.y, 1, 1);

		if (wrapBox.contains(mouseBox))
		{
			_waitingToMouseUpListener.reaction(listener, curEvent);
		}
		_waitingToMouseUpListener = BaseWindowObj::BaseListener();

	}
	void _handleButtonDown(SDL_Event* curEvent) 
	{
		for (auto& it : _clickListeners)
		{
			if (it.listener == nullptr)
			{
				continue;
			}

			auto itListener = (BaseWindowObj*)(it.listener);

			SDL_Rect itRect = itListener->getSizes();

			Box<int> wrapBox = Box<int>(itRect.x, itRect.y, itRect.w, itRect.h);

			Box<int> mouseBox = Box<int>(curEvent->button.x, curEvent->button.y, 1, 1);

			if (wrapBox.contains(mouseBox))
			{
				_waitingToMouseUpListener = it;
			}
		}

		for (auto& it : _buttonDownListeners)
		{
			if (it.listener == nullptr)
			{
				continue;
			}

			auto itListener = (BaseWindowObj*)(it.listener);

			SDL_Rect itRect = itListener->getSizes();

			Box<int> wrapBox = Box<int>(itRect.x, itRect.y, itRect.w, itRect.h);

			Box<int> mouseBox = Box<int>(curEvent->button.x, curEvent->button.y, 1, 1);

			if (wrapBox.contains(mouseBox))
			{
				it.reaction(it.listener, curEvent);
			}
		}



	};
	void _handleButtonUp(SDL_Event* curEvent) 
	{
		for (auto& it : _buttonUpListeners)
		{
			if (it.listener == nullptr)
			{
				continue;
			}

			auto itListener = (BaseWindowObj*)(it.listener);

			SDL_Rect itRect = itListener->getSizes();

			Box<int> wrapBox = Box<int>(itRect.x, itRect.y, itRect.w, itRect.h);

			Box<int> mouseBox = Box<int>(curEvent->button.x, curEvent->button.y, 1, 1);

			if (wrapBox.contains(mouseBox))
			{
				it.reaction(it.listener, curEvent);
			}
		}
	};

	BaseWindowObj::BaseListener _waitingToMouseUpListener;
	std::vector<BaseWindowObj::BaseListener> _clickListeners;

	std::vector<BaseWindowObj::BaseListener> _buttonDownListeners;
	std::vector<BaseWindowObj::BaseListener> _buttonUpListeners;


};


#endif // !__CLICK_MANAGER_H__


