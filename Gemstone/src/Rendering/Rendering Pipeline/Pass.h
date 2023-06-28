#pragma once

namespace Gem {
	// class IPass {
	// public:
	// 	IPass() = default;
	// 	IPass(const IPass& other) = default;
	// 	IPass(IPass&& other) noexcept = default;
	// 	IPass& operator=(const IPass& other) = default;
	// 	IPass& operator=(IPass&& other) noexcept = default;
	// 	virtual ~IPass() = default;
	//
	// 	virtual void* IProcess(void* input) = 0;
	// };
	//
	// template<typename Input, typename Output>
	// class Pass : public IPass {
	// public:
	// 	friend class Pipeline;
	//
	// 	virtual Output Process(Input input) = 0;
	//
	// private:
	// 	void* IProcess(void* input) override {
	// 		return &Process(*(Input*)input);
	// 	}
	// };
	//
	// struct Void {};
}