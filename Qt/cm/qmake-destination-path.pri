platform_path   = unknown-platform
compiler_path   = unknown-compiler
proccessor_path = unknown-processor
build-path      = unknown-build

PLATFORM_WIN {
    platform_path = windows
}

PLATFORM_LINUX {
    platform_path = linux
}

PLATFORM_OSX {
    platform_path = osx
}

COMPILER_GCC {
    compiler_path = gcc
}

COMPILER_MSVC2017 {
    compiler_path = msvc2017
}

COMPILER_CLANG {
    compiler_path = clang
}

PROCESSOR_x64 {
    processor_path = x64
} else {
    processor_path = x86
}

BUILD_DEBUG {
    build_path = debug
} else {
    build_path = release
}

DESTINATION_PATH = $$platform_path/$$compiler_path/$$processor_path/$$build_path
message(Dest. Path: $${DESTINATION_PATH})
