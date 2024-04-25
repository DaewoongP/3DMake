#include "ImguiManager.h"
using namespace Engine;

IMPLEMENT_SINGLETON(ImguiManager)

ImguiManager::~ImguiManager()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

HRESULT ImguiManager::Initialize(HWND hWnd, ComPtr<ID3D11Device> _device, ComPtr<ID3D11DeviceContext> _deviceContext)
{
	
	mDevice = _device;
	mDeviceContext = _deviceContext;
	
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();
	// Setup Platform/Renderer backends
	if (!ImGui_ImplWin32_Init(hWnd))
	{
		MessageBoxW(nullptr, TEXT("Engine::ImguiManager::Initialize\n Failed ImGui_ImplWin32_Init"), L"System Message", MB_OK);
		__debugbreak();
		return E_FAIL;
	}

	
	if (!ImGui_ImplDX11_Init(mDevice.Get(), mDeviceContext.Get()))
	{
		MessageBoxW(nullptr, TEXT("Engine::ImguiManager::Initialize\n Failed ImGui_ImplDX11_Init"), L"System Message", MB_OK);
		__debugbreak();
		return E_FAIL;
	}

	return S_OK;
}

void ImguiManager::Begin()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	if (show_demo_window)
		ImGui::ShowDemoWindow(&show_demo_window);

	// 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
	{
		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
		ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
		ImGui::Checkbox("Another Window", &show_another_window);

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
		ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		//ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
		ImGui::End();
	}
	
}

void ImguiManager::End()
{
	// Rendering
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}