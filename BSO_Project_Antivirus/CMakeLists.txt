cmake_minimum_required(VERSION 3.10.2)

project(BSOProjectAntivirus)

configure_file(BSOProjectAntivirusConfig.h.in BSOProjectAntivirusConfig.h)






target_include_directories(BSOProjectAntivirus PUBLIC
			"${PROJECT_BINARY_DIR}"
			)
