idf_component_register(
  SRCS 
      "c++/src/kj/parse/char.c++"
      "c++/src/kj/async-io.c++"
      "c++/src/kj/memory.c++"
      "c++/src/kj/list.c++"
      "c++/src/kj/string-tree.c++"
      "c++/src/kj/common.c++"
      "c++/src/kj/compat/gzip.c++"
      "c++/src/kj/compat/brotli.c++"
      "c++/src/kj/compat/url.c++"
      "c++/src/kj/compat/readiness-io.c++"
      "c++/src/kj/compat/tls.c++"
      "c++/src/kj/compat/http.c++"
      "c++/src/kj/time.c++"
      "c++/src/kj/cidr.c++"
      "c++/src/kj/units.c++"
      "c++/src/kj/refcount.c++"
      "c++/src/kj/filesystem.c++"
      "c++/src/kj/table.c++"
      "c++/src/kj/hash.c++"
      "c++/src/kj/source-location.c++"
      "c++/src/kj/mutex.c++"
      "c++/src/kj/encoding.c++"
      "c++/src/kj/timer.c++"
      "c++/src/kj/debug.c++"
      "c++/src/kj/array.c++"
      "c++/src/kj/string.c++"
      "c++/src/kj/thread.c++"
      "c++/src/kj/arena.c++"
      "c++/src/kj/io.c++"
      "c++/src/kj/exception.c++"
      "c++/src/capnp/c++.capnp.h"
      "c++/src/capnp/list.c++"
      "c++/src/capnp/any.c++"
      "c++/src/capnp/serialize-packed.c++"
      "c++/src/capnp/layout.c++"
      "c++/src/capnp/c++.capnp"
      "c++/src/capnp/serialize.c++"
      "c++/src/capnp/message.c++"
      "c++/src/capnp/blob.c++"
      "c++/src/capnp/compiler/error-reporter.c++"
      "c++/src/capnp/compiler/lexer.c++"
      "c++/src/capnp/compiler/type-id.c++"
      "c++/src/capnp/arena.c++"
      "c++/ekam-provider/c++header"
  INCLUDE_DIRS "c++/src"
  REQUIRES "cxx" 
)

target_compile_options(${COMPONENT_LIB} PRIVATE
    -fexceptions
    -frtti
    -DCAPNP_LITE=1
    -DKJ_HEADER_WARNINGS=0
)

target_compile_definitions(${COMPONENT_LIB} PUBLIC
    CAPNP_DISABLE_ENDIAN_DETECTION=1
    CAPNP_DISABLE_MMAP=1
    KJ_CUSTOM_CFLAGS
)