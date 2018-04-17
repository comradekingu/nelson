FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(PC_LIBFFI QUIET libffi)

FIND_PATH(LIBFFI_INCLUDE_DIR ffi.h
  HINTS ${PC_LIBFFI_INCLUDEDIR} ${PC_LIBFFI_INCLUDE_DIRS})

IF (LIBFFI_INCLUDE_DIR)
  FIND_LIBRARY(LIBFFI_LIBRARIES NAMES ffi
    HINTS ${PC_LIBFFI_LIBDIR} ${PC_LIBFFI_LIBRARY_DIRS})
ENDIF()

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LibFFI DEFAULT_MSG
                                  LIBFFI_LIBRARIES LIBFFI_INCLUDE_DIR)

MARK_AS_ADVANCED(LIBFFI_INCLUDE_DIR LIBFFI_LIBRARIES)