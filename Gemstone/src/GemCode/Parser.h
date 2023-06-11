#pragma once
#include "Entity Component System/EntityManager.h"

namespace Gem {
	enum Instructions {
		CREATE_GAME_OBJECT,
		ATTACH_TRANSFORM,
		ATTACH_CAMERA,
		ATTACH_MESH,
		ATTACH_COLOUR_MATERIAL
	};

	class GemCodeParser {
	public:
		GemCodeParser() = default;

		void ParseFile(const EntityManager& entityManager, const std::string& file);

	private:
		void Push(const int& value);
		int Pop();

		std::array<int, 128> m_Stack;
		size_t m_StackPointer;
	};
}