#pragma once

namespace Esperite {
	class UglyScene;

	class SceneManager {
	public:
		static SceneManager& get();

		void setScene(UglyScene& scene);
		[[nodiscard]] UglyScene* getScene() const; //TODO should be a shard_ptr or a ref?

	private:
		SceneManager() = default;

		UglyScene* m_Scene; //TODO should this be a shared ptr?
	};
}