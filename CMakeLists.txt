add_library(crc
	src/crc_16_ccitt.cpp
	src/crc_32c.cpp
)

target_include_directories(crc PUBLIC
	include/crc
)
