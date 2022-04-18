#pragma once

#include"Dusk/Core.h"
#include"Dusk/Events/Event.h"

namespace Dusk
{
	class DUSK_API Layer
	{
	public:
		Layer(const std::string debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		const std::string m_DebugName;
	};
}