#pragma once
#include "Event.h"

#include <sstream>

namespace Atlas
{
	class AT_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: X[" << m_MouseX << "] Y[" << m_MouseY << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		float m_MouseX, m_MouseY;
	};

	class AT_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_OffsetX(xOffset), m_OffsetY(yOffset) {}

		inline float GetXOffset() const { return m_OffsetX; }
		inline float GetYOffset() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollEvent: Offset X[" << m_OffsetX << "] Offset Y[" << m_OffsetY << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		float m_OffsetX, m_OffsetY;
	};

	class AT_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	protected:
		MouseButtonEvent(int button) : m_Button(button) {}

		int m_Button;
	};

	class AT_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MousePressedEvent: Button[" << m_Button << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class AT_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseReleasedEvent: Button[" << m_Button << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}