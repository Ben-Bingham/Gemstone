#pragma once

#include "Shader.h"

namespace Ruby {
	class VertexShader : public Shader {
	public:
		struct LayoutDataElement {
			enum class DataType {
				NONE,
				VECTOR_3F,
				VECTOR_2F
			};

			enum class DataName {
				NONE,
				POSITION,
				NORMAL,
				TEXTURE_COORDINATES
			};

			LayoutDataElement(DataType type = DataType::NONE, DataName name = DataName::NONE);

			DataType type;
			DataName name;
		};

		struct LayoutData {
			LayoutData(
				LayoutDataElement location1 = LayoutDataElement{ LayoutDataElement::DataType::NONE, LayoutDataElement::DataName::NONE },
				LayoutDataElement location2 = LayoutDataElement{ LayoutDataElement::DataType::NONE, LayoutDataElement::DataName::NONE },
				LayoutDataElement location3 = LayoutDataElement{ LayoutDataElement::DataType::NONE, LayoutDataElement::DataName::NONE }
			);

			LayoutDataElement location1;
			LayoutDataElement location2;
			LayoutDataElement location3;
		};

		VertexShader(const TextFile& shaderSourceFile, const LayoutData layoutData);

		[[nodiscard]] LayoutData getLayout() const;

	private:
		LayoutData m_LayoutData;
	};
}