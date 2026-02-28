#pragma once
#include <cstdint>
#include <optional>
#include <bitset>

enum class EvId : uint8_t {
	e1 = 1,
	e2 = 2,
	e4 = 4,
	e6 = 6,
};

struct Event {
	uint8_t node;
	EvId id;
};
