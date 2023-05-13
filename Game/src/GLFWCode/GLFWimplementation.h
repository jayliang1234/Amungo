#pragma once

#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"
namespace Game
{
	class GLFWimplementation : public WindowImplementation
	{
	public:

		virtual void CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void CreateWindow(int width, int height, std::string&& windowName) override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) override;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) override;

	private:
		struct Callbacks
		{
			std::function<void(const KeyPressed&)> keyPressedFunc;
			std::function<void(const KeyReleased&)> keyReleasedFunc;
		} mCallbacks;

		GLFWwindow* mWindow{ nullptr };

	};

}