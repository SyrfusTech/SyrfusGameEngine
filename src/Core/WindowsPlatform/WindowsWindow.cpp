#include "WindowsWindow.hpp"
#include "Core/WindowsPlatform/WindowsLookupTables.hpp"
#include "Core/Engine.hpp"
#include "Core/Input/KeyboardEvents.hpp"
#include "Core/Input/MouseEvents.hpp"
#include "Core/Input/WindowEvents.hpp"

#include <iostream>
#include <windowsx.h>

namespace SyrfusGameEngine
{
	LRESULT CALLBACK EventCallbackFunction(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_CLOSE:
		{
			WindowCloseEvent e;
			Engine::DispatchEvent(e);
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		case WM_SIZE:
		{
			WindowResizeEvent e(LOWORD(lParam), HIWORD(lParam));
			Engine::DispatchEvent(e);
			break;
		}
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		{
			KeyCode key = WindowsLookupTables::s_KeyCode[wParam];
			uint32_t repeatCount = lParam & 0xffff;
			if (wParam == VK_SHIFT)
			{
				key = GetKeyState(VK_LSHIFT) & 0x8000 ? WindowsLookupTables::s_KeyCode[VK_LSHIFT] : WindowsLookupTables::s_KeyCode[VK_RSHIFT];
			}
			else if (wParam == VK_CONTROL)
			{
				key = GetKeyState(VK_LCONTROL) & 0x8000 ? WindowsLookupTables::s_KeyCode[VK_LCONTROL] : WindowsLookupTables::s_KeyCode[VK_RCONTROL];
			}
			else if (wParam == VK_MENU)
			{
				key = GetKeyState(VK_LMENU) & 0x8000 ? WindowsLookupTables::s_KeyCode[VK_LMENU] : WindowsLookupTables::s_KeyCode[VK_RMENU];
			}
			KeyDownEvent e(key, repeatCount);
			Engine::DispatchEvent(e);
			break;
		}
		case WM_KEYUP:
		case WM_SYSKEYUP:
		{
			KeyCode key = WindowsLookupTables::s_KeyCode[wParam];
			uint32_t mask = 1 << 24;
			if (wParam == VK_CONTROL)
			{
				key = lParam & mask ? WindowsLookupTables::s_KeyCode[VK_RCONTROL] : WindowsLookupTables::s_KeyCode[VK_LCONTROL];
			}
			else if (wParam == VK_MENU)
			{
				key = lParam & mask ? WindowsLookupTables::s_KeyCode[VK_RMENU] : WindowsLookupTables::s_KeyCode[VK_LMENU];
			}
			else if (wParam == VK_SNAPSHOT) // Windows doesn't generate a keydown event for this key??
			{
				KeyDownEvent e(WindowsLookupTables::s_KeyCode[wParam], 1);
				Engine::DispatchEvent(e);
			}
			else if (wParam == VK_SHIFT) // Windows Doesn't generate a key up event for both shifts
			{
				KeyUpEvent e(WindowsLookupTables::s_KeyCode[VK_RSHIFT]);
				Engine::DispatchEvent(e);
			}
			KeyUpEvent e(key);
			Engine::DispatchEvent(e);
			break;
		}
		case WM_LBUTTONDOWN:
		case WM_MBUTTONDOWN:
		case WM_RBUTTONDOWN:
		case WM_XBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_MBUTTONUP:
		case WM_RBUTTONUP:
		case WM_XBUTTONUP:
		{
			MouseCode mouse = MouseCode::UNDEFINED_BUTTON;
			bool down = false;
			if (uMsg == WM_LBUTTONDOWN || uMsg == WM_LBUTTONUP)
			{
				mouse = WindowsLookupTables::s_MouseCode[VK_LBUTTON];
			}
			else if (uMsg == WM_MBUTTONDOWN || uMsg == WM_MBUTTONUP)
			{
				mouse = WindowsLookupTables::s_MouseCode[VK_MBUTTON];
			}
			else if (uMsg == WM_RBUTTONDOWN || uMsg == WM_RBUTTONUP)
			{
				mouse = WindowsLookupTables::s_MouseCode[VK_RBUTTON];
			}
			else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1)
			{
				mouse = WindowsLookupTables::s_MouseCode[VK_XBUTTON1];
			}
			else
			{
				mouse = WindowsLookupTables::s_MouseCode[VK_XBUTTON2];
			}
			if (uMsg == WM_LBUTTONDOWN || uMsg == WM_RBUTTONDOWN || uMsg == WM_MBUTTONDOWN || uMsg == WM_XBUTTONDOWN)
			{
				down = true;
			}
			if (down)
			{
				MouseButtonDownEvent e(mouse);
				Engine::DispatchEvent(e);
			}
			else
			{
				MouseButtonUpEvent e(mouse);
				Engine::DispatchEvent(e);
			}
			break;
		}
		case WM_MOUSEMOVE:
		{
			MouseMovedEvent e(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			Engine::DispatchEvent(e);
			break;
		}
		case WM_MOUSEWHEEL:
		{
			MouseScrolledEvent e(0.0, (double)GET_WHEEL_DELTA_WPARAM(wParam)/(double)WHEEL_DELTA);
			Engine::DispatchEvent(e);
			break;
		}
		case WM_MOUSEHWHEEL:
		{
			MouseScrolledEvent e((double)GET_WHEEL_DELTA_WPARAM(wParam)/(double)WHEEL_DELTA, 0.0);
			Engine::DispatchEvent(e);
			break;
		}
		default:
		{
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
		}
		return 0;
	}

	WindowsWindow::WindowsWindow(WindowProperties windowProps)
		: Window(windowProps), m_hInstance(GetModuleHandle(nullptr))
	{
		WNDCLASS wndClass = {};
		wndClass.lpszClassName = m_WindowProps.windowTitle.c_str();
		wndClass.hInstance = m_hInstance;
		wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.lpfnWndProc = EventCallbackFunction;

		RegisterClass(&wndClass);

		DWORD style = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX;

		RECT rect;
		rect.left = m_WindowProps.xPos;
		rect.top = m_WindowProps.yPos;
		rect.right = rect.left + m_WindowProps.width;
		rect.bottom = rect.top + m_WindowProps.height;

		AdjustWindowRect(&rect, style, false);

		m_hWnd = CreateWindowEx(
			0,
			m_WindowProps.windowTitle.c_str(),
			m_WindowProps.windowTitle.c_str(),
			style,
			rect.left,
			rect.top,
			rect.right - rect.left,
			rect.bottom - rect.top,
			NULL,
			NULL,
			m_hInstance,
			NULL
		);

		ShowWindow(m_hWnd, SW_SHOW);
	}

	WindowsWindow::~WindowsWindow()
	{
		DestroyWindow(m_hWnd);
		UnregisterClass(m_WindowProps.windowTitle.c_str(), m_hInstance);
	}

	int WindowsWindow::DispatchEvents()
	{
		MSG msg = {};

		while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		return 0;
	}
}