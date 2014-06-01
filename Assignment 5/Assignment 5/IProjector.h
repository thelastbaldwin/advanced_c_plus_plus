#pragma once

namespace Framework{
	class IProjector
	{
	public:
		virtual void projectCanvas (HCanvas const& canvas) = 0;
	};
}

