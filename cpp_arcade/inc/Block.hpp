//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Block header file
//

#include "Vec2.hpp"

namespace arc {
	class Block {
	public:
		Block(int textureIdxParam, const arc::Vec2<float> &posParam)
			: textureIdx(textureIdxParam), pos(posParam)
			{}
		~Block() = default;

		void operator=(int textureIdxParam) {
			textureIdx = textureIdxParam;
		}
		void operator=(const arc::Vec2<float> &posParam) {
			pos = posParam;
		}
		void operator=(const arc::Block &blockParam) {
			textureIdx = blockParam.textureIdx;
			pos = blockParam.pos;
		}
	public:
		int textureIdx;
		arc::Vec2<float> pos;
	};
}
